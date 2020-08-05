#include <iostream>
#include <algorithm>
using namespace std;

int T, ans, pay[4], minValue[13];

void solve(int idx, int sum) {
	if (idx > 12) {
		ans = min(ans, sum);
		return;
	}
	if (idx <= 10) {
		int threeMonths = minValue[idx] + minValue[idx + 1] + minValue[idx + 2];
		if (threeMonths > pay[2])
			solve(idx + 3, sum + pay[2]);
	}
	solve(idx + 1, sum + minValue[idx]);
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++)
			cin >> pay[i];
		ans = pay[3];
		int d;
		for (int i = 1; i <= 12; i++) {
			cin >> d;
			minValue[i] = min(pay[0] * d, pay[1]);
		}
		solve(1, 0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
