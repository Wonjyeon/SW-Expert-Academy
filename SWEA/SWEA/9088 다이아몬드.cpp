#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K;
int arr[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;

		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		int l = 0, r = 0, ans = 0;
		while (r < N&&l <= r) {
			if (arr[r] - arr[l] > K)\
				l++;
			else
				ans = max(r++ - l + 1, ans);
		}
		cout << "#" << tc << " " << ans << endl;
	}
}