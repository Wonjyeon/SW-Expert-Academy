#include <iostream>
#include <math.h>
using namespace std;

void fprint(int tc, int ans) {
	cout << "#" << tc << " " << ans << "\n";
}

int main()
{
	int T, C, P;
	int ans;

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int min = 1000000, max = -1;
		cin >> C;
		for (int i = 0; i < C; i++) {
			cin >> P;
			if (C == 1) {
				ans = P * P;
				break;
			}
			if (P > max)
				max = P;
			if (P < min)
				min = P;
			ans = max * min;
		}
		fprint(tc, ans);
	}
}

