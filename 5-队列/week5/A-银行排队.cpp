#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = n;
	queue<int> myQe;
	queue<char> myQc;
	while (cnt--) {
		char c;
		cin >> c;
		myQc.push(c);
	}
	cnt = n;
	while (cnt--) {
		int x;
		cin >> x;
		myQe.push(x);
	}
	int sumA = 0,sumB = 0,sumC = 0;
	int cntA = 0, cntB = 0, cntC = 0;
	cnt = n;
	while (cnt--) {
		char itemp = myQc.front();
		if (itemp == 'A') {
			sumA += myQe.front();
			myQe.pop();
			cntA++;
		}
		else if (itemp == 'B') {
			sumB += myQe.front();
			myQe.pop();
			cntB++;
		}
		else if(itemp == 'C') {
			sumC += myQe.front();
			myQe.pop();
			cntC++;
		}
		myQc.pop();
	}
	cout << sumA / cntA << endl;
	cout << sumB / cntB << endl;
	cout << sumC / cntC << endl;
}