#include <iostream>
#include <string>
using namespace std;

int chk(string op) {
	return op == "+" || op == "*" || op == "-" || op == "/";
}

int main() {
	int N, idx, temp1, temp2, ans;
	string op;

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		ans = 1;
		for (int i = 1; i <= N; i++) {
			cin >> idx >> op;

			//2���� ���� �θ� -> �� ������ ������
			if (i * 2 + 1 <= N) {
				cin >> temp1 >> temp2;
				if (!chk(op)) {
					ans = 0;
				}
			}
			// 1���� ���� �θ� -> ������ Ʋ���� ��.
			else if (i * 2 <= N) {
				cin >> temp1;
				ans = 0;
			}
			// �� leaf ��� -> op�� ���ڿ��� ��
			else {
				if (chk(op)) {
					ans = 0;
				}
			}
		}
		if (ans == 1)
			cout << "#" << tc << " " << ans << endl;
		else
			cout << "#" << tc << " " << ans << endl;
	}
}