#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int T, N, total;
	int score[101];
	int result[10001];
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		memset(result, 0, sizeof(result));
		memset(score, 0, sizeof(score));
		result[0] = 1;
		int ans = 0;
		total = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &score[i]);
			total += score[i];
			for (int j = total; j >= 0; j--) {
				if (result[j] > 0) {
					result[j + score[i]]++;
				}
			}
			result[score[i]]++;
		}
		for (int i = 0; i <= total; i++) {
			if (result[i] > 0)
				ans++;
		}
		printf("#%d %d\n", tc, ans);
	}

}