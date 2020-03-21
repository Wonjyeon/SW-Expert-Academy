#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000];
int N, MAX = -1;

void solve() {
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
	}
	for (int i = 0; i < N; i++) {
		MAX = max(MAX, dp[i]);
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		MAX = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			dp[i] = arr[i];
		}
		solve();
		cout << "#" << tc << " " << MAX << endl;
	}
}