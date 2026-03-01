#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* num = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < n; i++) {
			int min = 99999;
			int index = i;
			for (int j = i; j < n; j++) {
				if (num[j] < min) {
					min = num[j];
					index = j;
				}
			}
			
			int temp = num[i];
			num[i] = min;
			num[index] = temp;
		}

		int min_mius = 99999;
		for (int i = 0; i < n - 1; i++) {
			if (abs(num[i + 1] - num[i]) < min_mius) {
				min_mius = num[i + 1] - num[i];
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (abs(num[i + 1] - num[i]) == min_mius) {
				cout << "[" << num[i] << "," << num[i + 1] << "] ";
			}
		}
		cout << endl;
	}
	return 0;
}