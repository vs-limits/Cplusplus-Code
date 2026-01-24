#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<char> s;
	int t;
	cin >> t;
	while (t--) {
		string str_in;
		int len;
		cin >> str_in;
		len = str_in.length();
		for (int i = 0; i < len; i++) {
			s.push(str_in[i]);
		}
		for (int i = 0; i < len; i++) {
			char c = s.top();
			cout << c;
			s.pop();
		}
		cout << endl;
	}
}