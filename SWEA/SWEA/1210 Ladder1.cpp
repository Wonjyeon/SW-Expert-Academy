#include <iostream>
#include <cstring>
using namespace std;

int result = 0;

int visit[100][102];
int map[100][102];

void dfs(int x, int y) {
	if (x == 0) {
		result = y - 1;
		return;
	}
	visit[x][y] = 1;
	if (map[x][y + 1] && !visit[x][y + 1])
		dfs(x, y + 1);
	else if (map[x][y - 1] && !visit[x][y - 1])
		dfs(x, y - 1);
	else if (map[x - 1][y] && !visit[x - 1][y])
		dfs(x - 1, y);
}

int main() {
	int T;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> T;
		result = 0;
		int FinX, FinY;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					FinX = i;
					FinY = j;
				}
			}
		}
		dfs(FinX, FinY);
		cout << "#" << T << " " << result << endl;
	}
}