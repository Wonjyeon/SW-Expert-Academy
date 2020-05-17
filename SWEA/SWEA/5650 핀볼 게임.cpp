#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Block {
	int dir1, dir2, n_dir1, n_dir2;
};
Block block[5];

int T, N, map[100][100], ans, sx, sy;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> wormhole[11];

bool wall(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

void playGame(int x, int y, int dir) {
	int cnt = 0;
	while (1) {
		x += dx[dir], y += dy[dir];
		// µµÂøÁ¡À¸·Î µ¹¾Æ¿Â °æ¿ì || ºí·¢È¦¿¡ ºüÁø °æ¿ì
		if ((x == sx&&y == sy) || map[x][y] == -1) {
			ans = max(ans, cnt);
			break;
		}
		// º®¿¡ ºÎµúÈù °æ¿ì, 5¹ø ºí·ÏÀ» ¸¸³µÀ» °æ¿ì
		if (wall(x, y) || map[x][y] == 5) {
			dir = (dir + 2) % 4;
			cnt++;
			continue;
		}
		// ºó °ø°£ÀÎ °æ¿ì
		else if (map[x][y] == 0)
			continue;
		// ºí·Ï¿¡ ºÎµúÈù °æ¿ì
		else if (map[x][y] >= 1 && map[x][y] <= 4) {
			int b_type = map[x][y];
			if (dir == block[b_type].dir1)
				dir = block[b_type].n_dir1;
			else if (dir == block[b_type].dir2)
				dir = block[b_type].n_dir2;
			else
				dir = (dir + 2) % 4;
			cnt++;
		}
		// ¿úÈ¦¿¡ Åë°úµÈ °æ¿ì
		else if (map[x][y] >= 6) {
			int w_type = map[x][y];
			if (x == wormhole[w_type][0].first && y == wormhole[w_type][0].second)
				x = wormhole[w_type][1].first, y = wormhole[w_type][1].second;
			else
				x = wormhole[w_type][0].first, y = wormhole[w_type][0].second;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	block[1].dir1 = 3, block[1].n_dir1 = 0, block[1].dir2 = 2, block[1].n_dir2 = 1;
	block[2].dir1 = 0, block[2].n_dir1 = 1, block[2].dir2 = 3, block[2].n_dir2 = 2;
	block[3].dir1 = 1, block[3].n_dir1 = 2, block[3].dir2 = 0, block[3].n_dir2 = 3;
	block[4].dir1 = 2, block[4].n_dir1 = 3, block[4].dir2 = 1, block[4].n_dir2 = 0;

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		ans = 0;
		for (int i = 6; i < 11; i++) {
			wormhole[i].clear();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6)
					wormhole[map[i][j]].push_back({ i,j });		// ¿úÈ¦
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					sx = i, sy = j;
					for (int d = 0; d < 4; d++) {
						playGame(i, j, d);
					}
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}