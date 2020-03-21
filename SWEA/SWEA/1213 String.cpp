#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, word;
	int T = 10, tc;
	while (T--) {

		int cnt = 0;
		cin >> tc >> word >> str;
		int wl = word.length();
		int sl = str.length();
		for (int i = 0; i <= sl - wl; i++) {
			int flag = 1;
			for (int j = 0; j < wl; j++) {
				if (str[i + j] != word[j]) {
					flag = 0;
				}
			}
			if (flag == 1)
				cnt++;
		}
		cout << "#" << tc << " " << cnt << endl;
	}
}