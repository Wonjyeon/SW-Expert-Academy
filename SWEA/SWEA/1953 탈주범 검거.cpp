#include <iostream>
#include <cstring>
using namespace std;

int N, M, T, R, C, L, ans;
int map[50][50];
int visit[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int pipe[8][4] = { 0,0,0,0,
1,1,1,1,
1,0,1,0,
0,1,0,1,
1,0,0,1,
0,0,1,1,
0,1,1,0,
1,1,0,0 };

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void Answer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] != 0)
				ans++;
		}
	}
}

void dfs(int x, int y, int type, int time) {
	visit[x][y] = time;
	if (time == L)
		return;
	for (int dir = 0; dir < 4; dir++) {
		if (pipe[type][dir]) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (chk(nx, ny) && map[nx][ny] != 0) {
				if (!visit[nx][ny] || visit[nx][ny] > time + 1) {
					int next_type = map[nx][ny];
					int new_dir = (dir + 2) % 4;
					if (pipe[next_type][new_dir]) {
						dfs(nx, ny, next_type, time + 1);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		memset(visit, 0, sizeof(visit));
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		dfs(R, C, map[R][C], 1);
		Answer();
		cout << "#" << tc << " " << ans << endl;
	}
}