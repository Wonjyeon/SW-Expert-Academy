#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int map[20][20];
int visit[101];
int T, N, MAX, sx, sy;
int dx[] = { -1,1,1,-1 };
int dy[] = { 1,1,-1,-1 };
int dir_cnt[4];

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void dfs(int x, int y, int dir, int sum) {
	visit[map[x][y]] = 1;
	for (int i = 0; i <= 1; i++) {
		if (dir == 0 && sx == x && sy == y && i == 1)
			break;
		dir = (dir + i) % 4;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 출발지점이고 마지막 방향이야.
		if (nx == sx&&ny == sy&&dir == 3) {
			MAX = max(MAX, sum + 1);
			return;
		}
		// 못가. 해당 방향으로는 처음이었어. -> 다시 그 전으로 돌아가.
		if (!chk(nx, ny) || visit[map[nx][ny]]) {
			if (dir_cnt[dir] == 0)
				return;
		}
		else {
			dir_cnt[dir]++;
			dfs(nx, ny, dir, sum + 1);
			visit[map[nx][ny]] = 0;		// 다른 루트로 다시 방문할 수도 있어!
			dir_cnt[dir]--;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		MAX = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i < N - 1; i++) {
			for (int j = 0; j < N - 2; j++) {
				memset(visit, 0, sizeof(visit));
				memset(dir_cnt, 0, sizeof(dir_cnt));
				sx = i;
				sy = j;
				dfs(i, j, 0, 0);
			}
		}
		cout << "#" << tc << " " << MAX << endl;
	}
}