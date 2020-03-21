#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;

string postfix(string str) {
	int n = str.size();
	stack<char> s;
	string post;

	for (int i = 0; i < n; i++) {
		// 숫자일 때
		if (str[i] - '0' >= 0 && str[i] - '9' <= 0) {
			post += str[i];
		}
		// 연산자일 때
		else {
			if (s.empty() || str[i] == '(')
			{
				s.push(str[i]);
				continue;
			}

			switch (str[i]) {
			case '+':
			case '-':
				while (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/') {
					post += s.top();
					s.pop();
					if (s.empty())
						break;
				}
				s.push(str[i]);
				break;
			case '*':
			case '/':
				while (s.top() == '*' || s.top() == '/') {
					post += s.top();
					s.pop();
					if (s.empty())
						break;
				}
				s.push(str[i]);
				break;
			case ')':
				while (s.top() != '(') {
					post += s.top();
					s.pop();
				}
				s.pop();
				break;
			}
		}
	}
	while (!s.empty()) {
		post += s.top();
		s.pop();
	}
	return post;
}

int cal(string str) {
	int ans = 0;

	stack<int> s;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		if (str[i] - '0' >= 0 && str[i] - '9' <= 0) {
			s.push(str[i] - '0');
		}
		else {
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			switch (str[i]) {
			case '+':
				s.push(x + y);
				break;
			case '-':
				s.push(x - y);
				break;
			case '*':
				s.push(x * y);
				break;
			case '/':
				s.push(x / y);
				break;
			}
		}
	}
	ans = s.top();
	s.pop();
	return ans;
}

int main() {
	int N;
	string str;
	string post;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		cin >> str;
		post = postfix(str);
		cout << "#" << tc << " " << cal(post) << endl;
	}
}