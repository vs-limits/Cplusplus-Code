//#include<iostream>
//using namespace std;
//
//struct index {
//	int start;
//	int end;
//	int Max;
//};
//
//int main() {
//	int n;
//	while (cin >> n) {
//		int* arr = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		int k;
//		cin >> k;
//		index* indexes = new index[k];
//		for(int i = 0;i < k; i++) {
//			cin >> indexes[i].Max;
//		}
//
//		for (int i = 0; i < k; i++) {
//			for (int j = 0; j < n; j++) {
//				if (i == 0) {
//					indexes[0].start = 0;
//				}
//				if (indexes[i].Max < arr[j]) {
//					indexes[i].end = j - 1;
//					if (i + 1 < k) {
//						indexes[i + 1].start = j;
//					}
//					break;
//				}
//				if (j == n - 1) {
//					indexes[i].end = n - 1;
//				}
//			}
//		}
//
//		int t;
//		cin >> t;
//		while (t--) {
//			int x;
//			cin >> x;
//			int cnt = 0;
//			int found = 0;
//			for(int i = 0;i < k; i++) {
//				cnt++;
//				if (indexes[i].Max >= x) {
//					for (int j = indexes[i].start; j <= indexes[i].end; j++) {
//						cnt++;
//						if (arr[j] == x) {
//							found = 1;
//							cout << j + 1 << "-" << cnt << endl;
//							break;
//						}
//					}
//					if (found == 0) {
//						cout << "error" << endl;
//						break;
//					}
//				}else if(x > indexes[k - 1].Max) {
//					cout << "error" << endl;
//					break;
//				}
//			}
//		}
//	}
//}