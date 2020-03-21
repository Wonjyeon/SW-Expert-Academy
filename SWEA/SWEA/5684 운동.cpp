#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M, T, MIN, start;
int memo[401];	// 싸이클이 발견되면 해당 싸이클을 제외한 경로 빼주기 위해.
int visit[401];
vector<pair<int, int>> v[401];

void dfs(int x, int sum) {
	// 이미 MIN보다 길다면 더 이상 가지 X.
	if (sum >= MIN)
		return;
	if (x == start && visit[x]) {
		MIN = min(MIN, sum);
		return;
	}
	visit[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		// 이미 방문했던 곳 -> 싸이클!
		if (visit[v[x][i].first]) {
			MIN = min(MIN, sum + v[x][i].second - memo[v[x][i].first]);
			continue;
		}
		else {
			memo[v[x][i].first] = sum + v[x][i].second;
			dfs(v[x][i].first, sum + v[x][i].second);
		}
		visit[v[x][i].first] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		MIN = INF;
		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			v[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int s, e, c;
			cin >> s >> e >> c;
			v[s].push_back({ e,c });
		}
		for (int i = 1; i <= N; i++) {
			memset(visit, 0, sizeof(visit));
			memset(memo, 0, sizeof(memo));
			start = i;
			memo[i] = 0;
			dfs(i, 0);
		}
		if (MIN == INF)
			cout << "#" << tc << " " << -1 << endl;
		else
			cout << "#" << tc << " " << MIN << endl;
	}
}