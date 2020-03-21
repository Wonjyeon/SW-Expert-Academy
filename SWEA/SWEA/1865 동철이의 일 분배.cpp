#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N = 0;
double MAX = -1;
double map[17][17];
double visit[17];
int Select[17];

void dfs(int idx, int depth, double tmp) {
	if (depth == N) {
		MAX = tmp;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (Select[i])
			continue;
		if (map[idx][i] == 0)
			continue;
		if (tmp * map[idx][i] < MAX)
			continue;
		visit[idx] = map[idx][i];
		Select[i] = 1;
		dfs(idx + 1, depth + 1, tmp*map[idx][i]);
		visit[idx] = 0;
		Select[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		MAX = -1;
		memset(visit, 0, sizeof(visit));
		memset(Select, 0, sizeof(Select));
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				double n;
				cin >> n;
				map[i][j] = n / 100;
			}
		}
		dfs(1, 0, 1);
		MAX *= 100;
		printf("#%d %0.6f\n", tc, MAX);
	}
}