#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, K, max_high, ans, map[8][8], visit[8][8];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void dfs(int x, int y, int cnt, int flag) {
	ans = max(ans, cnt);
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!chk(nx, ny) || visit[nx][ny]) continue;
		if (map[nx][ny] < map[x][y]) {
			dfs(nx, ny, cnt + 1, flag);
		}
		else if (map[nx][ny] >= map[x][y]) {
			if (flag == 0) {
				if (map[nx][ny] - K >= map[x][y]) continue;
				int tmp = map[nx][ny];
				map[nx][ny] = map[x][y] - 1;
				dfs(nx, ny, cnt + 1, 1);
				map[nx][ny] = tmp;
			}
			else continue;
		}
	}
	visit[x][y] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		max_high = -1;
		ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				max_high = max(max_high, map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_high) {
					dfs(i, j, 1, 0);
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}