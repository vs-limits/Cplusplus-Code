//#include<iostream>
//using namespace std;
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int m, n;
//		cin >> m >> n;
//		int* key = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> key[i];
//		}
//		
//		int* H = new int[m];
//		for (int i = 0; i < m; i++) {
//			H[i] = -1;
//		}
//		for (int i = 0; i < n; i++) {
//			int mv = 1;
//			int index = key[i] % 11;
//			if (H[index] == -1) {
//				H[index] = key[i];
//			}
//			else {
//				while (H[index + mv] != -1) {
//					if (index + mv <= 11) {
//						mv++;
//					}
//					else if (index + mv > 11) {
//						index = 0;
//						mv = 0;
//					}
//				}
//				H[index + mv] = key[i];
//			}
//		}
//
//		for (int i = 0; i < m; i++) {
//			if (H[i] != -1) {
//				cout << H[i];
//			}
//			else if (H[i] == -1) {
//				cout << "NULL";
//			}
//			if (i != m - 1) {
//				cout << " ";
//			}
//			else if (i == m - 1) {
//				cout << endl;
//			}
//		}
//
//		int k;
//		cin >> k;
//		while (k--) {
//			int wait;
//			cin >> wait;
//			int found = 0, cnt = 0, station = -1;
//			int i = wait % 11;
//			while (found != 1) {
//				if (i >= m) {
//					i = 0;
//				}
//				if(H[i] != wait && H[i] != -1) {
//					cnt++;
//					i++;
//					continue;
//				}
//				else if (H[i] == wait) {
//					found = 1;
//					cnt++;
//					i++;
//					station = i;
//					break;
//				}
//				else if (H[i] == -1) {
//					cnt++;
//					i++;
//					break;
//				}
//			}
//			if (station == -1) {
//				cout << found << " " << cnt << endl;
//			}
//			else {
//				cout << found << " " << cnt << " " << station << endl;
//			}
//
//		}
//	}
//	return 0;
//}