#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, K, ans, Top, map[8][8], visit[8][8];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void dfs(int x, int y, int flag, int depth, int visit[8][8]) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 이미 방문했거나 범위를 벗어나면
		if (visit[nx][ny] || !chk(nx, ny)) {
			ans = max(ans, depth);
			continue;
		}
		// 가려는 곳이 더 높거나 같다면
		else if (map[nx][ny] >= map[x][y]) {
			// 이미 K만큼 뺐거나 빼도 갈 수 없다면
			if (flag == 1 || map[nx][ny] - K >= map[x][y]) {
				ans = max(ans, depth);
				continue;
			}
		}
		if (map[nx][ny] >= map[x][y]) {
			int tmp = map[nx][ny];
			map[nx][ny] = map[x][y] - 1;
			dfs(nx, ny, 1, depth + 1, visit);
			map[nx][ny] = tmp;
		}
		else {
			dfs(nx, ny, flag, depth + 1, visit);
		}
	}
	visit[x][y] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		Top = 0;
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (Top < map[i][j])
					Top = map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == Top) {
					memset(visit, 0, sizeof(visit));
					dfs(i, j, 0, 1, visit);
				}
			}
		}
		cout << "#" << tc << " " << ans << endl;
	}
}