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
		if (!chk(nx, ny) || visit[nx][ny]) continue;		// 범위를 벗어났다면
		if (map[nx][ny] < map[x][y]) {						// 가려는 곳이 더 낮다면
			dfs(nx, ny, cnt + 1, flag);
		}
		else if (map[nx][ny] >= map[x][y]) {				// 가려는 곳이 더 높다면
			if (flag == 0) {								// 아직 등산로를 깎은 적이 없다면
				if (map[nx][ny] - K >= map[x][y]) continue;	// 최대한 깎아도 같거나 높다면
				int tmp = map[nx][ny];
				map[nx][ny] = map[x][y] - 1;
				dfs(nx, ny, cnt + 1, 1);
				map[nx][ny] = tmp;
			}
			else continue;									// 이미 깎은 적이 있다면
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
					memset(visit, 0, sizeof(visit));
					dfs(i, j, 1, 0);
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}