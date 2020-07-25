#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int T, N, maxValue, minValue;
int op[4];
int num[4];

void dfs(int depth, int sum) {
	if (depth == N) {
		maxValue = max(maxValue, sum);
		minValue = min(minValue, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		op[i]--;
		if (i == 0)
			dfs(depth + 1, sum + num[depth]);
		else if (i == 1)
			dfs(depth + 1, sum - num[depth]);
		else if (i == 2)
			dfs(depth + 1, sum*num[depth]);
		else
			dfs(depth + 1, sum / num[depth]);
		op[i]++;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		maxValue = -INF;
		minValue = INF;
		for (int i = 0; i < 4; i++) {
			cin >> op[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		dfs(1, num[0]);
		cout << '#' << tc << ' ' << maxValue - minValue << '\n';
	}
	return 0;
}
