/*
	TSP 알고리즘
*/

//#include <iostream>
//#include <cmath>
//using namespace std;
//
//struct node {
//	int x = 0, y = 0;
//};
//node arr[12];
//int T, N, dist[12][12];
//int dp[12][(1 << 10)];
//
//int tsp(int v, int visit) {
//	if (visit == (1 << N) - 1)
//		return dist[v][N + 1];
//	if (dp[v][visit]) return dp[v][visit];
//	int Min = 987654321;
//	for (int i = 1; i <= N; i++) {
//		if (visit&(1 << (i - 1))) continue;
//		int tmp = dist[v][i] + tsp(i, visit | 1 << (i - 1));
//		if (Min > tmp) Min = tmp;
//	}
//	return dp[v][visit] = Min;
//}
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		cin >> N;
//		cin >> arr[0].x >> arr[0].y >> arr[N + 1].x >> arr[N + 1].y;
//		for (int i = 1; i <= N; i++)
//			cin >> arr[i].x >> arr[i].y;
//		for (int i = 0; i < N + 1; i++)
//			for (int j = i + 1; j < N + 2; j++)
//				dist[i][j] = dist[j][i] = abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y);
//		for (int i = 0; i < N + 2; i++)
//			for (int j = 0; j < (1 << N); j++)
//				dp[i][j] = 0;
//		cout << '#' << tc << ' ' << tsp(0, 0) << '\n';
//	}
//}


/*
	순열
*/
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct pos {
//	int x, y;
//};
//int N;
//pos arr[12];
//int idx[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
//
//
//int main() {
//	int T;
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		int MIN = 987654321;
//		cin >> N;
//		cin >> arr[0].x >> arr[0].y >> arr[N + 1].x >> arr[N + 1].y;
//		for (int i = 1; i <= N; i++) {
//			cin >> arr[i].x >> arr[i].y;
//		}
//		do {
//			int sum = 0;
//			for (int i = 1; i <= N + 1; i++) {
//				sum += abs(arr[idx[i]].x - arr[idx[i - 1]].x) + abs(arr[idx[i]].y - arr[idx[i - 1]].y);
//			}
//			MIN = min(sum, MIN);
//		} while (next_permutation(idx + 1, idx + 1 + N));
//		cout << "#" << tc << " " << MIN << '\n';
//	}
//}