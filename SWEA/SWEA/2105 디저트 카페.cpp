#include <iostream>
#include <algorithm>
using namespace std;

int T, N, sc, sr, ans = -1, map[21][21];
int dc[] = { 1,1,-1,-1 };		//행
int dr[] = { 1,-1,-1,1 };		//열
bool visit[101];

void dfs(int c, int r, int dir, int cnt) {
	visit[map[c][r]] = true;
	int nc = c + dc[dir], nr = r + dr[dir];

	if (dir == 3 && nc == sc && nr == sr) {
		ans = max(ans, cnt);
		return;
	}

	if (nc >= 0 && nc < N&&nr >= 0 && nr < N && !visit[map[nc][nr]]) {
		visit[map[nc][nr]] = true;
		dfs(nc, nr, dir, cnt + 1);
		if (dir < 3)
			dfs(nc, nr, dir + 1, cnt + 1);
		visit[map[nc][nr]] = false;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				sc = i, sr = j;
				visit[map[i][j]] = true;
				dfs(i, j, 0, 1);
				visit[map[i][j]] = false;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}
