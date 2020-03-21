#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, MAX = -1, ans_Num, cnt;
int map[1000][1000];
int dp[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void dfs(int x, int y) {
	dp[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx, ny)) {
			if (map[nx][ny] == map[x][y] + 1) {
				dfs(nx, ny);
				dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		MAX = -1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dp[i][j] == 0) {
					dfs(i, j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (MAX < dp[i][j]) {
					MAX = dp[i][j];
					ans_Num = map[i][j];
				}
				else if (MAX == dp[i][j]) {
					ans_Num = min(ans_Num, map[i][j]);
				}
			}
		}
		printf("#%d %d %d\n", tc, ans_Num, MAX);
	}
}