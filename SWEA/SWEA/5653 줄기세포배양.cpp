#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> Pair;

int T, N, M, K;
bool visit[350][350];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		cin >> N >> M >> K;
		int e;
		for (int i = 150; i < N + 150; i++) {
			for (int j = 150; j < M + 150; j++) {
				cin >> e;
				if (e > 0) {
					visit[i][j] = true;
					pq.push({ { e, -e },{ i,j } });
				}
			}
		}
		for (int time = 1; time < K; time++) {
			while (!pq.empty() && pq.top().first.first == time) {
				int x = pq.top().second.first;
				int y = pq.top().second.second;
				int p = -pq.top().first.second;
				pq.pop();
				if (p == 100) continue;
				pq.push({ { time + p - 1, -100 },{ x, y } });
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (visit[nx][ny] == 0) {
						visit[nx][ny] = 1;
						pq.push({ { time + p + 1, -p },{ nx, ny } });
					}
				}
			}
		}
		cout << '#' << tc << ' ' << pq.size() << '\n';
		memset(visit, false, sizeof(visit));
	}
	return 0;
}