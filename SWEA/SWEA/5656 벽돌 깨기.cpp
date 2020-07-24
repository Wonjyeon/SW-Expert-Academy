#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, N, W, H, ans, total = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<vector<int>> map(15, vector<int>(12,0));

bool isWall(int x, int y) {
	return x < 0 || y < 0 || x >= H || y >= W;
}

void arrange() {
	while (1) {
		int cnt = 0;
		for (int w = 0; w < W; w++) {
			for (int h = H - 2; h >= 0; h--) {
				if (map[h][w] == 0) continue;
				else if (map[h + 1][w] != 0) continue;
				map[h + 1][w] = map[h][w];
				map[h][w] = 0;
				cnt++;
			}
		}
		if (cnt == 0) return;
	}
}

void solve(int n, int total) {
	if (total == 0) {
		ans = 0;
		return;
	}
	if (n == N) {
		ans = min(ans, total);
		return;
	}
	vector<vector<int>> tmp = map;
	int w, h;								// w : 열, h : 행
	for (w = 0; w < W; w++) {
		if (map[H-1][w] == 0) continue;		// 해당 열에는 남은 벽돌이 없다.
		for (h = 0; h < H; h++) {			// 벽돌 위치까지 내려감.
			if (map[h][w] != 0) break;
		}
		if (map[h][w] == 1) {
			map[h][w] = 0;
			solve(n + 1,  total - 1);
		}
		else {
			queue<pair<pair<int, int>, int>> q;
			q.push({ {h, w}, map[h][w] });
			map[h][w] = 0;
			int cnt = 1;
			while (!q.empty()) {
				int x = q.front().first.first;
				int y = q.front().first.second;
				int dist = q.front().second - 1;
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x;
					int ny = y;
					for (int k = 0; k < dist; k++) {
						nx += dx[dir];
						ny += dy[dir];
						if (isWall(nx, ny)) break;
						
						if (map[nx][ny] >= 1) {
							if (map[nx][ny] > 1)
								q.push({ {nx,ny}, map[nx][ny] });
							map[nx][ny] = 0;
							cnt++;
						}
					}
				}
			}
			arrange();
			solve(n + 1, total - cnt);
		}
		map = tmp;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 1) ans++;
			}
		}
		solve(0, ans);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}
