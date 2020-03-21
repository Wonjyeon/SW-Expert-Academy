#include <iostream>
using namespace std;

int visit[16][16] = { 0, };
int map[16][16] = { 0, };
int startX, startY, destX, destY;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int result = 0;

void init() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			visit[i][j] = 0;
		}
	}
	result = 0;
}

void dfs(int x, int y) {
	if (result == 1)
		return;

	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == destX&&ny == destY) {
			result = 1;
			return;
		}
		if (nx >= 0 && nx < 16 && ny >= 0 && ny < 16) {
			if (!visit[nx][ny] && map[nx][ny] == 0) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int t;
	for (int tc = 1; tc <= 10; tc++) {
		init();
		scanf("%d", &t);

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					startX = i;
					startY = j;
				}
				else if (map[i][j] == 3) {
					destX = i;
					destY = j;
				}
			}
		}
		dfs(startX, startY);
		printf("#%d ", t);
		if (result == 1) {
			printf("1\n");
		}
		else
			printf("0\n");
	}
}