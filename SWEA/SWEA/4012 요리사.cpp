#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int T, N, answer;
int synergy[16][16];
bool check[16];

void dfs(int idx, int depth) {
	if (depth == N / 2) {
		int aSum = 0, bSum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (check[i] && check[j]) 
					aSum += synergy[i][j];
				else if (!check[i] && !check[j])
					bSum += synergy[i][j];
			}
		}
		answer = min(answer, abs(aSum - bSum));
		return;
	}
	for (int i = idx; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		dfs(i + 1, depth + 1);
		check[i] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		answer = INF;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> synergy[i][j];
			}
		}
		dfs(0, 0);
		cout << '#' << tc << ' ' << answer << '\n';
	}
	return 0;
}
