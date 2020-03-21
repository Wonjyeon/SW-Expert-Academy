#include <iostream>
#include <vector>
using namespace std;

struct mountain {
	int x = 0;
	int y = 0;
	int K = 0;

};
int num[50001];
int T, N, ans;
vector<mountain> v;

void solve() {
	int flag = 0, up = 0, K = 0;
	for (int i = 1; i < N; i++) {
		// 올라감.
		if (num[i] < num[i + 1]) {
			// 처음 올라가는 것.
			if (flag == 0 && up == 0) {
				up = i;
			}
			// 내려가던 중.
			else if (flag == 1) {
				flag = 0;
				mountain m;
				m.x = up; m.y = i; m.K = K;

				v.push_back(m);
				up = i;
			}

		}
		// 내려감.
		else {
			// 처음 내려가는 것. -> 봉우리를 만들 수 없음.
			if (up == 0)
				continue;
			// 올라가던 중 만남.
			if (flag == 0) {
				K = i;
				flag = 1;
			}
			if (i == N - 1) {
				mountain m;
				m.x = up; m.y = i + 1; m.K = K;
				v.push_back(m);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		for (int i = 0; i < v.size(); i++)
			v.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> num[i];
		}
		solve();
		for (int i = 0; i < v.size(); i++) {
			int x_range = v[i].K - v[i].x;
			int y_range = v[i].y - v[i].K;
			ans += x_range * y_range;
		}
		cout << "#" << tc << " " << ans << endl;
	}

}