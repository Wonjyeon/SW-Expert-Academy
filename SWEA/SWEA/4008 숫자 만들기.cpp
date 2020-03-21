#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100000001;
int T, N, MAX, MIN, num[12], op[4];

void dfs(int cnt, int sum) {
	if (cnt == N) {
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)
			continue;
		op[i]--;
		if (i == 0)
			dfs(cnt + 1, sum + num[cnt]);
		else if (i == 1)
			dfs(cnt + 1, sum - num[cnt]);
		else if (i == 2)
			dfs(cnt + 1, sum*num[cnt]);
		else if (i == 3)
			dfs(cnt + 1, sum / num[cnt]);
		op[i]++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		MIN = INF;
		MAX = -INF;
		cin >> N;
		for (int i = 0; i < 4; i++)
			cin >> op[i];
		for (int i = 0; i < N; i++)
			cin >> num[i];
		dfs(1, num[0]);
		cout << "#" << tc << " " << MAX - MIN << '\n';
	}
}