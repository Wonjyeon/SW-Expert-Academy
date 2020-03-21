#include <iostream>
using namespace std;

int N;
long double Dist[10], Weight[10];

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%Lf", &Dist[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%Lf", &Weight[i]);
		}
		printf("#%d ", tc);
		for (int i = 0; i < N - 1; i++) {
			long double L = Dist[i], R = Dist[i + 1];
			int cnt = 0;
			while (L < R&&cnt <= 50) {
				long double m = (L + R) / 2;
				long double sum = 0;
				for (int k = 0; k < N; k++) {
					if (m < Dist[k])
						sum += Weight[k] / ((Dist[k] - m)*(Dist[k] - m));
					else
						sum -= Weight[k] / ((Dist[k] - m)*(Dist[k] - m));
				}
				if (sum < 0)
					L = m;
				else
					R = m;
				cnt++;
			}
			printf("%.10Lf ", L);
		}
		printf("\n");
	}
	return 0;
}