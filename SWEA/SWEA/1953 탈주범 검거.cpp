#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M, R, C, L;
int map[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int visit[50][50];

int pipe[8][4] = {
	0,0,0,0,
	1,1,1,1,		//1번
	1,0,1,0,		//2번
	0,1,0,1,		//3번
	1,0,0,1,		//4번
	0,0,1,1,		//5번
	0,1,1,0,		//6번
	1,1,0,0			//7번
};

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int bfs(int r, int c) {
	queue<pair<int, int>> q;
	memset(visit, 0, sizeof(visit));
	int ans = 1;
	visit[r][c] = 1;
	q.push({ r, c });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		int t = map[x][y];
		q.pop();
		if (visit[x][y] == L) return ans;
		for (int i = 0; i < 4; i++) {
			if (pipe[t][i] == 1) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!chk(nx, ny) || visit[nx][ny] || map[nx][ny] == 0) continue;
				int nt = map[nx][ny];
				if (pipe[nt][(i + 2) % 4] == 1) {
					q.push({ nx, ny });
					visit[nx][ny] = visit[x][y] + 1;
					ans++;
				}
			}
		}
	}
	return ans;
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
		cout << '#' << tc << ' ' << bfs(R, C) << '\n';
	}
}