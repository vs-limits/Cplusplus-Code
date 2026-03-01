#include<iostream>
using namespace std;

void sort(int num[],int low,int high,int n) {
	if (low < high) {
		int pivot = num[low];
		int i = low;
		int j = high;

		while (i < j) {
			while (i < j && num[j] >= pivot) {
				j--;
			}
			if (i < j) {
				num[i] = num[j];
				i++;
			}

			while (i < j && num[i] < pivot) {
				i++;
			}
			if (i < j) {
				num[j] = num[i];
				j--;
			}
		}

		num[i] = pivot;
		
		for (int k = 0; k < n; k++) {
			cout << num[k];
			if (k < n - 1) cout << " ";
		}
		cout << endl;

		sort(num, low, i - 1, n);
		sort(num, i + 1, high, n);
	}
}

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

		if (n == 1) {
			continue;
		}
		else {
			sort(num, 0, n - 1, n);
		}
		
	}
}