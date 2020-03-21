#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		int *arr = new int[N];
		int max = -1;

		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
			if (arr[j] > max)
				max = arr[j];
		}

		int ans = N + max;
		for (int j = 0; j < N; j++)
		{
			ans += arr[j];
		}

		cout << "#" << i << " " << ans << endl;
	}
}