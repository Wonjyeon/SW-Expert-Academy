#include <iostream>
using namespace std;

int main()
{
	int T, t, n;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int grade[101] = { 0 };
		int max = -1;
		int ans = 0;

		cin >> t;
		for (int i = 0; i < 1000; i++) {
			cin >> n;
			grade[n]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (grade[i] >= max) {
				max = grade[i];
				ans = i;
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}