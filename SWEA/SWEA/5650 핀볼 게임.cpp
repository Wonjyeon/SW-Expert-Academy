#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

typedef pair<int, int> pa;
int T, N, max_score = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[MAX][MAX];
vector<pa> wormhole[11];
vector<pa> startMap;

int solve(int sx, int sy, int dir) {
	int x = sx, y = sy;
	int score = 0;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		// 출발 지점 or 블랙홀
		if ((x == sx && y == sy) || map[x][y] == -1)
			return score;
		// 벽 or 5번 블록
		if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 5) {
			dir = (dir + 2) % 4;
			score++;
		}
		// 빈 공간
		else if (map[x][y] == 0) 
			continue;
		// 웜홀
		else if (map[x][y] > 5) {
			int wid = map[x][y];
			int x1 = wormhole[wid][0].first;
			int y1 = wormhole[wid][0].second;
			int x2 = wormhole[wid][1].first;
			int y2 = wormhole[wid][1].second;
			if (x == x1 && y == y1) x = x2, y = y2;
			else x = x1, y = y1;
		}
		// 1~4 블록
		else {
			score++;
			if (map[x][y] == 1) {
				if (dir == 2) dir = 1;
				else if (dir == 3) dir = 0;
				else dir = (dir + 2) % 4;
			}
			else if (map[x][y] == 2) {
				if (dir == 3) dir = 2;
				else if (dir == 0) dir = 1;
				else dir = (dir + 2) % 4;
			}
			else if (map[x][y] == 3) {
				if (dir == 0) dir = 3;
				else if (dir == 1) dir = 2;
				else dir = (dir + 2) % 4;
			}
			else if (map[x][y] == 4) {
				if (dir == 1) dir = 0;
				else if (dir == 2) dir = 3;
				else dir = (dir + 2) % 4;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 0)
					startMap.push_back({ i,j });
				else if (map[i][j] > 5)
					wormhole[map[i][j]].push_back({ i,j });
			}
		}
		for (int i = 0; i < startMap.size(); i++) {
			for (int d = 0; d < 4; d++) {
				int sx = startMap[i].first;
				int sy = startMap[i].second;
				max_score = max(max_score, solve(sx, sy, d));
			}
		}
		cout << '#' << tc << ' ' << max_score << '\n';
		max_score = 0;
		for (int i = 6; i <= 10; i++)
			wormhole[i].clear();
		startMap.clear();
	}
	return 0;
}
