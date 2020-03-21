#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string bin[] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
string target[10] = { "211","221","122","411","132","231","114","312","213","112" };

string conv(string s) {
	string re = "";
	int num;
	for (int i = 0; i < s.size(); i++) {
		// A(65) ~
		if (s[i] >= 65) {
			num = s[i] - 55;
		}
		// 숫자
		else {
			num = s[i] - '0';
		}
		re += bin[num];

	}
	return re;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;
		int n, m;
		cin >> n >> m;
		//암호코드 저장용(중복없애기)
		vector<string> vs;
		vector<string> univers;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			int uniflag = 1;

			// 이미 존재 -> 추가X.
			for (int u = 0; u < univers.size(); u++) {
				if (str == univers[u]) {
					uniflag = 0;
					break;
				}
			}
			if (uniflag == 0) {
				continue;
			}
			univers.push_back(str);
			//2진수로 먼저 바꾼다.
			string trans = conv(str);
			//연속된 1 개수 세기
			int cnt = 0;
			int cntzero = 0;
			vector<int> vi;
			for (int j = 0; j < trans.size(); j++) {
				// 1이 나오면 0 카운트 했던거 push.
				if (trans[j] != '0') {
					vi.push_back(cntzero);
					cntzero = 0;
					// 0이 나오기 전까지 1 카운트++
					while (j < trans.size() && trans[j] != '0') {
						cnt++;
						j++;
					}
					cntzero++;
					vi.push_back(cnt);
					cnt = 0;
				}
				else {
					cntzero++;
				}
			}
			// 전부 0이었어 -> 1이 안나왔으니까 cntzero를 넣지 X.
			if (vi.empty()) {
				continue;
			}

			vector<int> numbers;
			//4개=숫자1개 , 32개=숫자8개=암호코드1개
			for (int j = 0; j <= vi.size(); j += 4) {
				if ((j != 0 && j % 32 == 0) || j == vi.size()) {
					string tmp = "";
					for (int k = 0; k < numbers.size(); k++) {
						tmp += to_string(numbers[k]);
					}
					int flag = 1;
					for (int k = 0; k < vs.size(); k++) {
						if (tmp == vs[k]) {
							flag = 0;
							break;
						}
					}
					if (flag) {
						vs.push_back(tmp);
						int oddsum = 0;
						int evensum = 0;
						int last = numbers[7];
						for (int k = 0; k < 7; k++) {
							if (k % 2 == 0) {
								oddsum += numbers[k];
							}
							else {
								evensum += numbers[k];
							}
						}
						int test = oddsum * 3 + evensum + last;
						if (test % 10 == 0) {
							ans += oddsum + evensum + last;
						}
					}
					if (j == vi.size())
						break;
					numbers.clear();
				}
				int a = vi[j + 1];
				int b = vi[j + 2];
				int c = vi[j + 3];
				//a,b,c중 가장 작은수로 나눠준다
				int mini = min({ a, b, c });
				a /= mini;
				b /= mini;
				c /= mini;
				string find = "";
				find += '0' + a;
				find += '0' + b;
				find += '0' + c;
				for (int k = 0; k < 10; k++) {
					if (find == target[k]) {
						numbers.push_back(k);
						break;
					}
				}
			}

		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}