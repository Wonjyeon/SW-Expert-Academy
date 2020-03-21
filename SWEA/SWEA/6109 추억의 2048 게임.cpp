#include <iostream>
#include <string>
using namespace std;

int N, map[20][20];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, int dir) {
	int curX = x, curY = y;
	int nx = x, ny = y;
	for (int i = 0; i < N - 1; i++) {
		nx += dx[dir];
		ny += dy[dir];

		if (map[curX][curY]) {
			if (map[nx][ny]) {
				if (map[curX][curY] == map[nx][ny]) {
					map[curX][curY] *= 2;
					map[nx][ny] = 0;
					curX += dx[dir];
					curY += dy[dir];
				}
				else {
					curX += dx[dir];
					curY += dy[dir];
					if (curX != nx || curY != ny) {
						map[curX][curY] = map[nx][ny];
						map[nx][ny] = 0;
					}
				}
			}
		}
		else {
			if (map[nx][ny]) {
				map[curX][curY] = map[nx][ny];
				map[nx][ny] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string S;
		cin >> N >> S;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		if (S == "up") {
			for (int i = 0; i < N; i++)
				dfs(0, i, 0);
		}
		else if (S == "down") {
			for (int i = 0; i < N; i++)
				dfs(N - 1, i, 1);
		}
		else if (S == "left") {
			for (int i = 0; i < N; i++)
				dfs(i, 0, 2);
		}
		else if (S == "right") {
			for (int i = 0; i < N; i++)
				dfs(i, N - 1, 3);
		}
		cout << "#" << tc << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}
}