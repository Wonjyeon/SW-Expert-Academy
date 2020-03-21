#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Node {
	ll x, y;
};
int T, N, r[1001], p[1001];
Node a[1001];
double E;

void Make() {
	for (int i = 0; i < N; i++) {
		p[i] = i;
		r[i] = 0;
	}
}
int Find(int x) {
	return x == p[x] ? x : p[x] = Find(p[x]);
}
bool Union(int x, int y) {
	int nx = Find(x), ny = Find(y);
	if (nx == ny)
		return false;
	if (r[nx] < r[ny]) swap(nx, ny);
	p[ny] = nx;
	if (r[nx] == r[ny])
		r[nx]++;
	return true;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed;
	cout.precision(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		Make();
		ll ans = 0;
		for (int i = 0; i < N; i++)
			cin >> a[i].x;
		for (int i = 0; i < N; i++)
			cin >> a[i].y;
		cin >> E;
		vector<pair<ll, pair<int, int>>> edges;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				edges.push_back({ (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y) *(a[i].y - a[j].y) ,{ i,j } });
			}
		}
		sort(edges.begin(), edges.end());
		for (int i = 0; N > 1; i++) {
			if (Union(edges[i].second.first, edges[i].second.second)) {
				ans += edges[i].first;
				N--;
			}
		}
		cout << "#" << tc << " " << (double)(ans*E) << "\n";
	}
}