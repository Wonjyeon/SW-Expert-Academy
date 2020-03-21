#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N, tmp;
	for (int tc = 1; tc <= 10; tc++) {
		stack<int> s;
		stack<int> ans;
		cin >> N;
		scanf("%1d", &tmp);
		s.push(tmp);

		for (int i = 1; i < N; i++) {
			scanf("%1d", &tmp);
			if (!s.empty() && s.top() == tmp) {
				s.pop();
			}
			else
				s.push(tmp);
		}
		while (!s.empty()) {
			ans.push(s.top());
			s.pop();
		}
		printf("#%d ", tc);
		while (!ans.empty()) {
			printf("%d", ans.top());
			ans.pop();
		}
		printf("\n");
	}
}