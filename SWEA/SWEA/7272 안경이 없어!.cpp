#include <iostream>
#include <string>
using namespace std;

char hole[] = { 'A', 'D', 'O', 'P', 'Q', 'R' };
string TRUE = "SAME";
string FALSE = "DIFF";

int chk(char c) {
	if (c == 'B')
		return 2;
	for (int i = 0; i < 6; i++) {
		if (c == hole[i])
			return 1;
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	string str1, str2, ans;
	for (int tc = 1; tc <= T; tc++) {
		int flag = 0;

		cin >> str1 >> str2;
		int len1 = str1.size();
		int len2 = str2.size();
		if (len1 != len2) {
			ans = FALSE;
		}
		else {
			for (int i = 0; i < len1; i++) {
				if (chk(str1[i]) == chk(str2[i]))
					flag = 1;
				else {
					flag = 0;
					break;
				}
			}
			if (flag == 0)
				ans = FALSE;
			else
				ans = TRUE;
		}
		cout << "#" << tc << " " << ans << endl;
	}
}