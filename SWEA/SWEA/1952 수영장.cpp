#include <iostream>
#include <algorithm>
using namespace std;

int T, week[13], D[12], pay[4], ans;

void solve(int idx, int sum) {
	if (idx > 12) {
		ans = min(sum, ans);
		return;
	}
	int tmp = 0;
	if (idx <= 10) {
		tmp = D[idx] + D[idx + 1] + D[idx + 2];
		if (tmp > pay[2])
			solve(idx + 3, sum + pay[2]);
	}
	solve(idx + 1, sum + D[idx]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 987654321;
		for (int i = 0; i < 4; i++)
			cin >> pay[i];
		for (int i = 1; i < 13; i++) {
			cin >> week[i];
			D[i] = min(pay[1], week[i] * pay[0]);
		}
		solve(1, 0);
		cout << "#" << tc << " " << min(ans, pay[3]) << endl;
	}
}