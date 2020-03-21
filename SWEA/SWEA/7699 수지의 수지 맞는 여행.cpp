#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C, ans;
char map[20][20];
int visit[43];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int chk(int x, int y) {
	return x >= 0 && x < R&&y >= 0 && y < C;
}

void dfs(int x, int y, int count) {
	//cout << map[x][y] << " " << map[x][y] - '0' << endl;
	visit[map[x][y] - '0'] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx, ny) && !visit[map[nx][ny] - '0']) {
			dfs(nx, ny, count + 1);
		}
	}
	visit[map[x][y] - '0'] = 0;
	ans = max(ans, count);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visit, 0, sizeof(visit));
		ans = -1;
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0, 0, 1);
		cout << "#" << tc << " " << ans << endl;
	}
}