#include <iostream>
using namespace std;

int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int map[8][8];
int N, M;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void reset_map(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int color = map[x][y];
		bool check = false;
		int nx = x + dx[i];
		int ny = y + dy[i];

		while (chk(nx, ny) && map[nx][ny] != 0) {
			if (map[nx][ny] == color) {
				check = true;
				break;
			}
			nx += dx[i];
			ny += dy[i];
		}
		while (check) {
			if (nx == x && ny == y)
				break;
			map[nx][ny] = color;
			nx -= dx[i];
			ny -= dy[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		int white = 0;
		int black = 0;

		cin >> N >> M;
		int mid = (N / 2) - 1;
		map[mid][mid] = 2;
		map[mid + 1][mid + 1] = 2;
		map[mid][mid + 1] = 1;
		map[mid + 1][mid] = 1;

		while (M--) {
			int x, y, color;
			cin >> y >> x >> color;
			map[x - 1][y - 1] = color;
			reset_map(x - 1, y - 1);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1)
					black++;
				else if (map[i][j] == 2)
					white++;
			}
		}
		cout << "#" << tc << " " << black << " " << white << endl;
	}
	return 0;
}