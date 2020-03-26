#include <iostream>
#include <algorithm>
using namespace std;

int T, N, X[20], Y[20], visit[20];
long long Min;

void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		long long xSum = 0, ySum = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i])
				xSum += X[i], ySum += Y[i];
			else
				xSum -= X[i], ySum -= Y[i];
		}
		if (Min == -1) Min = (xSum*xSum) + (ySum*ySum);
		else Min = min(Min, (xSum*xSum) + (ySum*ySum));
	}
	for (int i = idx; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		dfs(i, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Min = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];
			visit[i] = 0;
		}
		dfs(0, 0);
		cout << '#' << tc << ' ' << Min << '\n';
	}
}