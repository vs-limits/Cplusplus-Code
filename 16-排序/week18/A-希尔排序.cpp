#include<iostream>
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

		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; i++) {
				int temp = num[i];
				int j = i;

				while (j >= gap && num[j - gap] < temp) {
					num[j] = num[j - gap];
					j -= gap;
				}

				num[j] = temp;
			}

			for (int i = 0; i < n; i++) {
				cout << num[i];
				if (i != n - 1) {
					cout << " ";
				}
				else {
					cout << endl;
				}
			}
		}

	}
}