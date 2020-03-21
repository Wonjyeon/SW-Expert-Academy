#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int map[1000][1000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int MIN = INF;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				cnt += map[i][j];
				if (i == j) continue;
				if (map[i][j] == 0) map[i][j] = INF;
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				if (i == k) continue;
				for (int j = 0; j < N; j++) {
					if (j == k || j == i) continue;
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				cnt += map[i][j];
			}
			MIN = min(MIN, cnt);
		}
		cout << '#' << tc << ' ' << MIN << '\n';
	}
	return 0;
}
