#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		double n;
		int radix;
		cin >> n >> radix;
		int intPart = (int)n;
		double decPart = n - intPart;
		stack<int> ints;
		while (intPart >= 1) {
			ints.push(intPart % radix);
			intPart /= radix;
		}
		queue<int> decs;
		while (decPart >= 1e-6) {
			int temp = (int)(decPart * radix);
			decs.push(temp);
			decPart = decPart * radix - temp;
		}
		if (ints.empty()) cout << 0;
		while (!ints.empty()) {
			if (ints.top() >= 10) {
				cout << (char)(ints.top() - 10 + 'A');
			}
			else {
				cout << ints.top();
			}
			ints.pop();
		}
		int cnt = 0;
		if (!decs.empty()) cout << ".";
		while (!decs.empty() && cnt < 3) {
			if (decs.front() >= 10) {
				cout << (char)(decs.front() - 10 + 'A');
			}
			else {
				cout << decs.front();
			}
			decs.pop();
			cnt++;
		}
		for (int i = 0; i < 3 - cnt; i++) cout << 0;
		cout << endl;
	}
}