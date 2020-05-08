#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M, R, C, L;
int map[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
bool visit[50][50];

int pipe[8][4] = {
	0,0,0,0,
	1,1,1,1,
	1,0,1,0,
	0,1,0,1,
	1,0,0,1,
	0,0,1,1,
	0,1,1,0,
	1,1,0,0
};

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int bfs(int r, int c) {
	queue<pair<int, int>> q;
	memset(visit, false, sizeof(visit));
	int ans = 0;
	visit[r][c] = true;
	q.push({ r, c });
	while (L) {
		int size = q.size();
		while (size--) {
			ans++;
			int x = q.front().first, y = q.front().second;
			int t = map[x][y];
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (pipe[t][i] == 1) {
					int nx = x + dx[i], ny = y + dy[i];
					if (!chk(nx, ny) || visit[nx][ny] || map[nx][ny] == 0) continue;
					int nt = map[nx][ny];
					if (pipe[nt][(i + 2) % 4] == 1) {
						q.push({ nx, ny });
						visit[nx][ny] = 1;
					}
				}
			}
		}
		L--;
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