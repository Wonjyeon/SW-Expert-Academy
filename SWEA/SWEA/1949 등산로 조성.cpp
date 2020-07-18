#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, K, max_length, max_height;
int map[10][10];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool visit[10][10];

void dfs(int x, int y, int length, bool flag) {
	visit[x][y] = true;
	max_length = max(max_length, length);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny]) continue;
		if (map[nx][ny] >= map[x][y]) {
			if (!flag && map[nx][ny] - K < map[x][y]) {
				int tmp = map[nx][ny];
				map[nx][ny] = map[x][y] - 1;
				dfs(nx, ny, length + 1, true);
				map[nx][ny] = tmp;
			}
		}
		else 
			dfs(nx, ny, length + 1, flag);
	}
	visit[x][y] = false;
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		max_height = 0;
		max_length = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				max_height = max(max_height, map[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_height) {
					dfs(i, j, 1, false);
				}
			}
		}
		cout << '#' << tc << ' ' << max_length << '\n';
	}
	return 0;
}
