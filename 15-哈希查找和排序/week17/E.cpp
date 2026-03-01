//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		int* arr = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//
//		int cnt = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = i+1; j < n; j++) {
//				if (arr[j] < arr[i]) {
//					int temp = arr[j];
//					arr[j] = arr[i];
//					arr[i] = temp;
//					cnt++;
//				}
//				else {
//					continue;
//				}
//			}
//		}
//
//		cout << cnt << endl;
//	}
//} 