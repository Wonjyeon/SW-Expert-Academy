#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pa;

int T, K, score;
int magnet[4][8];
pa rota[21];

void solve() {
	for (int k = 0; k < K; k++) {
		vector<pa> ro_magnet;
		int mNum = rota[k].first - 1;
		int dir = rota[k].second;
		ro_magnet.push_back({ mNum, dir });

		//왼쪽 확인
		int left = magnet[mNum][6];
		int tDir = (dir*-1);
		for (int i = mNum - 1; i >= 0; i--) {
			if (left != magnet[i][2]) {
				ro_magnet.push_back({ i, tDir });
				tDir *= -1;
				left = magnet[i][6];
			}
			else break;
		}

		//오른쪽 확인
		int right = magnet[mNum][2];
		tDir = (dir*-1);
		for (int i = mNum + 1; i < 4; i++) {
			if (right != magnet[i][6]) {
				ro_magnet.push_back({ i, tDir });
				tDir *= -1;
				right = magnet[i][2];
			}
			else break;
		}

		//회전
		for (int i = 0; i < ro_magnet.size(); i++) {
			int n = ro_magnet[i].first;
			int d = ro_magnet[i].second;

			// 시계 -> 오른쪽으로 이동.
			if (d == 1) {
				int tmp = magnet[n][7];
				for (int j = 6; j >= 0; j--) {
					magnet[n][j + 1] = magnet[n][j];
				}
				magnet[n][0] = tmp;
			}
			// 반시계 -> 왼쪽으로 이동.
			else {
				int tmp = magnet[n][0];
				for (int j = 1; j < 8; j++) {
					magnet[n][j - 1] = magnet[n][j];
				}
				magnet[n][7] = tmp;
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> K;
		score = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> rota[i].first >> rota[i].second;
		}
		solve();
		for (int i = 0; i < 4; i++) {
			if (magnet[i][0] == 1) 
				score += pow(2, i);
		}
		cout << '#' << tc << ' ' << score << '\n';
	}
	return 0;
}
