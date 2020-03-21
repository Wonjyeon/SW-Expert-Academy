#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int graph[100];
		int dump;
		int ans = 0;
		int d = 0;

		cin >> dump;

		for (int i = 0; i < 100; i++) {
			cin >> graph[i];
		}

		while (1) {
			sort(graph, graph + 100);

			if (d == dump) {
				ans = graph[99] - graph[0];
				break;
			}
			else if (graph[99] - graph[0] <= 1) {
				ans = graph[99] - graph[0];
				break;
			}
			graph[0]++;
			graph[99]--;
			d++;
		}
		printf("#%d %d\n", tc, ans);
	}
}