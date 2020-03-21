#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int T, N, MAX;
int bolt[50][2];
int visit[50];
queue<pair<int, int>> ans;

void dfs(int f, int r, queue<pair<int, int>> q) {
	for (int i = 0; i < N; i++) {
		if (visit[i])	continue;
		if (bolt[i][0] != r)	continue;
		visit[i] = 1;
		q.push({ bolt[i][0], bolt[i][1] });
		dfs(bolt[i][0], bolt[i][1], q);
	}
	if (q.size() > ans.size())
		ans = q;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		MAX = -1;
		for (int i = 0; i < N; i++) {
			cin >> bolt[i][0] >> bolt[i][1];
		}
		for (int i = 0; i < N; i++) {
			memset(visit, 0, sizeof(visit));
			if (bolt[i][0] != 0) {
				queue<pair<int, int>> q;
				q.push({ bolt[i][0], bolt[i][1] });
				visit[i] = 1;
				dfs(bolt[i][0], bolt[i][1], q);
				visit[i] = 0;
			}
		}
		cout << '#' << tc << ' ';
		while (!ans.empty()) {
			cout << ans.front().first << ' ' << ans.front().second << ' ';
			ans.pop();
		}
		cout << '\n';
	}
}