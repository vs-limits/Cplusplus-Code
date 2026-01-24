#include<iostream>
#include<stack>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		stack<char> s;
		string str;
		int len;
		cin >> str;
		len = str.length();
		for (int i = 0; i < len; i++) {
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
			else if (str[i] == '}') {
				if(!s.empty() && s.top() == '{') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
		}
		if (s.empty()) {
			cout << "ok" << endl;
		}
		else {
			cout << "error" << endl;
		}
	}
}