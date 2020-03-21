#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> t;
		int ans = 0;
		int arr[1000] = { 0, };
		int m1, m2, m3;

		for (int i = 0; i < t; i++) {
			cin >> arr[i];
		}
		for (int i = 2; i < t - 2; i++) {
			if (arr[i] - arr[i - 1] < 0 || arr[i] - arr[i - 2] < 0 || arr[i] - arr[i + 1] < 0 || arr[i] - arr[i + 2] < 0)
				continue;
			m1 = max(arr[i - 1], arr[i - 2]);
			m2 = max(arr[i + 1], arr[i + 2]);
			m3 = max(m1, m2);
			ans += arr[i] - m3;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}