#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int* num = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> num[i];
	}

	for (int i = 1; i < t; i++) {
		if (num[i] < num[i-1]) {
			int temp = num[i];

			int j;
			for (j = i - 1; j >= 0 && temp < num[j]; j--) {
				num[j + 1] = num[j];
			}

			num[j + 1] = temp;
		}

		for (int q = 0; q < t; q++) {
			cout << num[q] << " ";
		}
		cout << endl;
	}
}