#include <iostream>
#include <queue>
using namespace std;

int T, N, M, R, C, L;
int map[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int pipe[8][4] = {
	0,0,0,0,		
	1,1,1,1,		// 1번 파이프 (상, 하, 좌, 우)
	1,0,1,0,		// 2번 파이프 (상, 하)
	0,1,0,1,		// 3번 파이프 (좌, 우)
	1,1,0,0,		// 4번 파이프 (상, 우)
	0,1,1,0,		// 5번 파이프 (하, 우)
	0,0,1,1,		// 6번 파이프 (하, 좌)
	1,0,0,1			// 7번 파이프 (상, 좌)
};

bool isWall(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

int bfs() {
	int visited[50][50] = { 0, };
	queue<pair<int, int>> q;
	q.push({ R,C });
	visited[R][C] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int pipe_type = map[x][y];
		q.pop();
		if (visited[x][y] == L) break;
		for (int i = 0; i < 4; i++) {
			if (pipe[pipe_type][i]) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isWall(nx, ny) || visited[nx][ny] || map[nx][ny] == 0) continue;
				int nt = map[nx][ny];
				if (pipe[nt][(i + 2) % 4]) {
					q.push({ nx,ny });
					visited[nx][ny] = visited[x][y] + 1;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		cout << '#' << tc << ' ' << bfs() << '\n';
	}
}
