#include <iostream>
#include <algorithm>
using namespace std;

int T, D, W, K, ans;
int map[13][20];

bool check(int d, int num) {
	for (int i = 0; i < W; i++) {
		if (map[d][i] != num) return true;
	}
	return false;
}

bool pass() {
	for (int i = 0; i < W; i++) {
		bool flag = false;
		int cmp = map[0][i];
		int cnt = 1;
		for (int j = 1; j < D; j++) {
			if (cmp == map[j][i]) cnt++;
			else {
				cmp = map[j][i];
				cnt = 1;
			}
			if (cnt == K) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (cnt >= ans) return;
	if (idx >= D) {
		if (pass()) ans = min(ans, cnt);
		return;
	}
	dfs(idx + 1, cnt);

	int tmp[20];
	for (int i = 0; i < W; i++)
		tmp[i] = map[idx][i];
	for (int i = 0; i < W; i++)
		map[idx][i] = 0;
	dfs(idx + 1, cnt + 1);

	for (int i = 0; i < W; i++)
		map[idx][i] = 1;
	dfs(idx + 1, cnt + 1);

	for (int i = 0; i < W; i++)
		map[idx][i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;
		ans = D;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0, 0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}