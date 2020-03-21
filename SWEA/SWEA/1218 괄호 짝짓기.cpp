#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int str_l;

	for (int t = 1; t <= 10; t++) {
		stack<char> s;
		vector<char> v;
		int check = 1;
		cin >> str_l;
		for (int i = 0; i < str_l; i++) {
			char cc;
			cin >> cc;
			v.push_back(cc);
		}
		for (int i = 0; i < v.size(); i++) {
			switch (v[i]) {
			case '}':
				if (s.top() != '{')
					check = 0;
				else
					s.pop();
				break;
			case ')':
				if (s.top() != '(')
					check = 0;
				else
					s.pop();
				break;
			case '>':
				if (s.top() != '<')
					check = 0;
				else
					s.pop();
				break;
			case ']':
				if (s.top() != '[')
					check = 0;
				else
					s.pop();
				break;
			default:
				s.push(v[i]);
				break;
			}
			if (check == 0)
				break;
		}
		if (check == 0)
			cout << "#" << t << " " << 0 << endl;
		else
			cout << "#" << t << " " << 1 << endl;
	}
}