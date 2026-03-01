//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		int* arr = new int[n + 1];
//		for (int i = 1; i < n + 1; i++) {
//			cin >> arr[i];
//		}
//		int t;
//		cin >> t;
//		while (t--) {
//			int x;
//			cin >> x;
//			arr[0] = x;
//			for (int i = n; i >= 0; i--) {
//				if (i == 0) {
//					cout << "error" << endl;
//					break;
//				}
//				if (arr[0] == arr[i]) {
//					cout << i << endl;
//					break;
//				}
//			}
//		}
//	}
//}