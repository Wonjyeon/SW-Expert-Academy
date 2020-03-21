#include <iostream>
using namespace std;

int pow(int x, int y) {
	if (y == 1)
		return x;
	return x*pow(x, y - 1);
}

int main() {
	int T = 10, t, x, y;
	while (T--) {
		cin >> t >> x >> y;
		cout << "#" << t << " " << pow(x, y) << endl;
	}
}