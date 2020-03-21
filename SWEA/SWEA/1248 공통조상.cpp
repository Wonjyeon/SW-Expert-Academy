#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int sum = 1;

void dfs(vector<int> Tree[], int root) {
	sum += Tree[root].size();
	for (int i = 0; i < Tree[root].size(); i++) {
		int nroot = Tree[root][i];
		if (Tree[nroot].size() > 0)
			dfs(Tree, nroot);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, V, E, n1, n2;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<int> Tree[MAX];
		int parent[MAX];
		sum = 1;

		cin >> V >> E >> n1 >> n2;
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a;
			Tree[a].push_back(b);
		}
		if (parent[n1] == 1 || parent[n2] == 1) {
			cout << "#" << tc << " " << 1 << " " << V << endl;
			continue;
		}
		while (n1) {
			int next_p = parent[n1];
			parent[n1] = -1;
			n1 = next_p;
		}
		while (1) {
			if (parent[n2] == -1) {
				dfs(Tree, n2);
				cout << "#" << tc << " " << n2 << " " << sum << endl;
				break;
			}
			n2 = parent[n2];
		}
	}
}