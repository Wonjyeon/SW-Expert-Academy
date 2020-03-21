/*
	다익스트라
*/

#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
int T, N, dist[100][100], map[100][100];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

int dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	dist[0][0] = 0;
	pq.push({ -dist[0][0],{ 0,0 } });
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cur_dist = -pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (dist[nx][ny] > cur_dist + map[nx][ny]) {
				dist[nx][ny] = cur_dist + map[nx][ny];
				pq.push({ -dist[nx][ny],{ nx,ny } });
			}
		}
	}
	return dist[N - 1][N - 1];
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
				dist[i][j] = INF;
			}
		}
		cout << "#" << tc << " " << dijkstra() << "\n";
	}
}


/*
	DFS
*/

#include <iostream>
using namespace std;

int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int dp[100][100], map[100][100];
bool visit[100][100];
int N;

void dfs(int x, int y) {
	if (x == N - 1 && y == N - 1) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (visit[nx][ny]) continue;
		if (dp[N - 1][N - 1] > 0 && dp[N - 1][N - 1] <= dp[x][y] + map[nx][ny])
			continue;
		if (dp[nx][ny] > 0 && dp[nx][ny] <= dp[x][y] + map[nx][ny])
			continue;
		dp[nx][ny] = dp[x][y] + map[nx][ny];
		visit[nx][ny] = true;
		dfs(nx, ny);
		visit[nx][ny] = false;
	}
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
				visit[i][j] = false;
				dp[i][j] = 0;
			}
		}
		visit[0][0] = true;
		dfs(0, 0);
		cout << "#" << tc << " " << dp[N - 1][N - 1] << endl;
	}
	return 0;
}

/*
	BFS
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int T, N, ans, map[100][100], visit[100][100], dp[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dp[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == N - 1 && y == N - 1)
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (chk(nx, ny)) {
				if (dp[nx][ny] == -1 || dp[nx][ny] > dp[x][y] + map[nx][ny]) {
					dp[nx][ny] = dp[x][y] + map[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	string str;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			for (int j = 0; j < N; j++) {
				map[i][j] = str[j] - '0';
				dp[i][j] = -1;
			}
		}
		bfs();
		cout << "#" << tc << " " << dp[N - 1][N - 1] << endl;
	}
}