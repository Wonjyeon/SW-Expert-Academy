#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &t);
		queue<int> q;
		for (int i = 0; i < 8; i++) {
			int num;
			scanf("%d", &num);
			q.push(num);
		}
		int minus = 1;
		while (1) {
			if (minus == 6)
				minus = 1;
			int tmp = q.front() - minus;
			q.pop();
			if (tmp <= 0) {
				tmp = 0;
				q.push(tmp);
				break;
			}
			q.push(tmp);
			minus++;
		}
		printf("#%d ", t);
		while (!q.empty()) {
			printf("%d ", q.front());
			q.pop();
		}
		printf("\n");

	}
}