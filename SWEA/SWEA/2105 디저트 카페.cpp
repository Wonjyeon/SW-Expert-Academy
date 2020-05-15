#include <iostream>
#include <algorithm>
using namespace std;

int T, N, ans, sx, sy, map[21][21];
bool visit[101];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };

void dfs(int c, int r, int dir, int cnt) {
	visit[map[c][r]] = true;
	int x = c + dx[dir], y = r + dy[dir];
	// 마지막 방향이면서 처음 지점과 같음. -> 가능한 루트.
	if (dir == 3 && x == sx&&y == sy) {
		ans = max(ans, cnt);
		visit[map[c][r]] = false;
		return;
	}
	// 범위 안에 있으면서 아직 먹지 않은 디저트
	if (x >= 0 && x < N&&y >= 0 && y < N && !visit[map[x][y]]) {
		// 최대한 한 방향으로 쭉 감
		dfs(x, y, dir, cnt + 1);
		// 아직 방향이 끝나지 않았고, 그 다음 방향으로 진행.
		if (dir < 3)
			dfs(x, y, dir + 1, cnt + 1);
	}
	visit[map[c][r]] = false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		ans = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				sx = i, sy = j;
				dfs(i, j, 0, 1);
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}