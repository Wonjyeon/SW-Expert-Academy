#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int V, E;

void dfs(int x) {
	visit[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
		if (!visit[graph[x][i]])
			dfs(graph[x][i]);
	}
	cout << x << " ";
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int a, b;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < V; i++) {
			graph[i].clear();
		}
		cin >> V >> E;
		for (int i = 0; i<E; i++) {
			cin >> a >> b;
			graph[b].push_back(a);
		}
		cout << "#" << tc << " ";

		for (int i = 1; i <= V; i++) {
			if (!visit[i])
				dfs(i);
		}
		cout << endl;
	}
}