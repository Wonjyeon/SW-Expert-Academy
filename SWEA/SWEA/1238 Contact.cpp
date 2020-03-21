#include <iostream>
#include <queue>
using namespace std;

int contact[101][101];
int visit[101];

void init() {
	for (int i = 0; i < 101; i++) {
		visit[i] = 0;
		for (int j = 0; j < 101; j++) {
			contact[i][j] = 0;
		}
	}

}

int main() {
	int N, start;
	for (int tc = 1; tc <= 10; tc++) {
		init();
		int max = -1;
		cin >> N >> start;

		for (int i = 0; i < N / 2; i++) {
			int x, y;
			cin >> x >> y;
			contact[x][y] = 1;
		}

		queue<int> q;
		queue<int> last;
		q.push(start);
		visit[start] = 1;

		while (!q.empty()) {
			int q_size = q.size();
			while (!last.empty()) {
				last.pop();
			}
			while (q_size--) {
				int from = q.front();
				last.push(from);
				q.pop();
				for (int j = 0; j < 101; j++) {
					if (contact[from][j] == 1 && !visit[j]) {
						q.push(j);
						visit[j] = 1;
					}
				}
			}
		}
		while (!last.empty()) {
			int from = last.front();
			last.pop();
			if (max < from)
				max = from;
		}
		cout << "#" << tc << " " << max << endl;
	}
}