#include <iostream>
#include <vector>
#include <string>
using namespace std;

string arr[] = {
	"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111",
	"0001011"
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T, N, M, ptr, flag, cnt;
	int even, odd, val;
	string str;

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<int> v;
		flag = 0;
		cnt = 0, even = 0, odd = 0, val = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> str;
			if (flag)
				continue;
			for (int j = M - 1; j >= 0; j--) {
				if (str[j] == '1') {
					flag = 1;
					ptr = j;
					break;
				}
			}
			if (flag) {
				ptr -= 55;
				while (cnt < 8) {
					string sstr = str.substr(ptr, 7);
					for (int i = 0; i < 10; i++) {
						if (sstr == arr[i]) {
							v.push_back(i);
							break;
						}
					}
					cnt++;
					ptr += 7;
				}
			}
		}
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			ans += v[i];
			//cout << v[i] << " ";
			if (i % 2)
				sum += v[i];
			else
				sum += v[i] * 3;
		}
		if (sum % 10 == 0)
			cout << "#" << tc << " " << ans << endl;
		else
			cout << "#" << tc << " " << 0 << endl;
	}
}