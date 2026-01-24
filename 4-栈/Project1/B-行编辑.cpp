#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		stack<char> s;
		stack<char> temp;
		string str_in;
		int len;
		cin >> str_in;
		len = str_in.length();
		for (int i = 0; i < len; i++) {
			if (str_in[i] != '#') {
				s.push(str_in[i]);
			}
			else if(!s.empty() && str_in[i] == '#') {
				s.pop();
			}
		}
		int size = s.size();
		if (s.empty()) {
			cout << "NULL";
		}
		else {
			for (int i = 0; i < size; i++) {
				temp.push(s.top());
				s.pop();
			}
			for (int i = 0; i < size; i++) {
				cout << temp.top();
				temp.pop();
			}
		}
		cout << endl;
	}
}