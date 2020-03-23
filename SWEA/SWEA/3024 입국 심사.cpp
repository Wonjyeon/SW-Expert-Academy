#include <iostream>
using namespace std;

typedef long long ll;
int T, N, arr[100000];
ll M;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int MAX = -1;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (MAX < arr[i]) MAX = arr[i];
		}
		ll row = 1, high = M*MAX;
		while (row < high) {
			ll mid = (row + high) / 2;
			ll sum = 0;
			for (int i = 0; i < N; i++)
				sum += mid / arr[i];
			if (sum >= M) high = mid;
			else row = mid + 1;
		}
		cout << '#' << tc << ' ' << high << '\n';
	}
}