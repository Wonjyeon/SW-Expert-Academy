#include <iostream>
using namespace std;

int T, N, X, ans = 0;
int map[20][20];

void solve() {
	// 행 단위로 탐색
	for (int i = 0; i < N; i++) {
		int now_height = map[i][0];
		int cnt = 0;
		bool flag = false;
		bool available = true;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == now_height) {
				cnt++;
			}
			// 1칸 낮은 곳으로
			else if (map[i][j] == now_height - 1) {
				if (flag && cnt < X) {
					available = false;
					break;
				}
				flag = true;
				now_height = map[i][j];
				cnt = 1;
			}
			// 1칸 높은 곳으로
			else if (map[i][j] == now_height + 1) {
				if ((flag && cnt < 2 * X) || (!flag && cnt < X)) {
					available = false;
					break;
				}
				flag = false;
				now_height = map[i][j];
				cnt = 1;
			}
			else {
				available = false;
				break;
			}
		}
		if (available == false || flag == true && cnt < X)
			continue;
		ans++;
	}
	// 열 단위로 탐색
	for (int i = 0; i < N; i++) {
		int now_height = map[0][i];
		int cnt = 0;
		bool flag = false;
		bool available = true;
		for (int j = 0; j < N; j++) {
			if (map[j][i] == now_height) {
				cnt++;
			}
			// 1칸 낮은 곳으로
			else if (map[j][i] == now_height - 1) {
				if (flag && cnt < X) {
					available = false;
					break;
				}
				flag = true;
				now_height = map[j][i];
				cnt = 1;
			}
			// 1칸 높은 곳으로
			else if (map[j][i] == now_height + 1) {
				if ((flag && cnt < 2 * X) || (!flag && cnt < X)) {
					available = false;
					break;
				}
				flag = false;
				now_height = map[j][i];
				cnt = 1;
			}
			else {
				available = false;
				break;
			}
		}
		if (available == false || flag == true && cnt < X)
			continue;
		ans++;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> X;
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		solve();
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
