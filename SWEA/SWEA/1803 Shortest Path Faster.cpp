#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100010
typedef long long ll;
int T, N, M, start, dest;
vector<pair<int, int>> graph[MAX];
ll dist[MAX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> start >> dest;
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			dist[i] = 9999999999999999;
		}
		for (int i = 0; i < M; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			graph[x].push_back({ y, c });
			graph[y].push_back({ x, c });
		}
		priority_queue<pair<ll, int>> pq;
		pq.push({ 0,start });
		dist[start] = 0;
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();
			for (int i = 0; i < graph[here].size(); i++) {
				int next = graph[here][i].first;
				int nextcost = graph[here][i].second;
				if (dist[next] > cost + nextcost) {
					dist[next] = cost + nextcost;
					pq.push({ -dist[next],next });
				}
			}
		}
		cout << '#' << tc << ' ' << dist[dest] << '\n';
	}
}