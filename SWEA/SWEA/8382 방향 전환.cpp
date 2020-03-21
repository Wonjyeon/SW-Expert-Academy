#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, x1, x2, y1, y2, d1, d2, ans;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> x1 >> y1 >> x2 >> y2;
		d1 = abs(x1 - x2);
		d2 = abs(y1 - y2);
		int tmp = max(d1, d2) - min(d1, d2);
		ans = d1 + d2;
		if (tmp % 2 == 1)
			ans += tmp - 1;
		else
			ans += tmp;
		cout << "#" << tc << " " << ans << endl;
	}
}