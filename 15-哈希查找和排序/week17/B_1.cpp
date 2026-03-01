//#include<iostream>
//using namespace std;
//int di = 1;
//
//int get_di(int cnt) {
//	if (cnt % 2 == 0) {
//		return di * di;
//	}
//	else if (cnt % 2 == 1) {
//		di++;
//		return -((di - 1) * (di - 1));
//	}
//}
//
//int update_index(int index, int cnt) {
//	int d_t = get_di(cnt);
//	return index + d_t;
//}
//
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int m, n;
//		cin >> m >> n;
//		int* num = new int[n];
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//		}
//
//		int* H = new int[m];
//		for (int i = 0; i < m; i++) {
//			H[i] = -1;
//		}
//
//
//		for (int i = 0; i < n; i++) {
//			int index = num[i] % 11;
//			if (H[index] == -1) {
//				H[index] = num[i];
//			}
//			else {
//				int cnt = 0;
//				int new_index = index;
//				di = 1;
//				while (H[new_index] != -1) {
//					new_index = update_index(index, cnt);
//					cnt++;
//					if (new_index >= m) {
//						new_index %= m;
//					}
//					else if (new_index < 0) {
//						new_index = (new_index % m) + m;
//					}
//
//					if (H[new_index] == -1) {
//						H[new_index] = num[i];
//						break;
//					}
//				}
//			}
//		}
//
//		for (int i = 0; i < m; i++) {
//			if (H[i] == -1) {
//				cout << "NULL";
//			}
//			else {
//				cout << H[i];
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
//			int x;
//			cin >> x;
//			int index = x % 11;
//			int new_index = index;
//
//			int found = 0;
//			int cnt = 0;
//			int station = 0;
//			di = 1;
//
//			/*if (H[new_index] == x) {
//				found = 1;
//				cnt++;
//				station = new_index + 1;
//			}else {*/
//				while (found == 0 && cnt < m) {
//					if (H[new_index] == -1) {
//						cnt++;
//						break;
//					}
//					else if (H[new_index] != -1 && H[new_index] != x) {
//						new_index = update_index(index, cnt);
//						cnt++;
//						if (new_index >= m) {
//							new_index %= m;
//						}
//						else if (new_index < 0) {
//							new_index = (new_index % m) + m;
//						}
//					}
//
//					if (H[new_index] == x) {
//						found = 1;
//						cnt++;
//						station = new_index + 1;
//						break;
//					}
//				//}
//			}
//			if (found == 0) {
//				cout << found << " " << cnt << endl;
//			}
//			else {
//				cout << found << " " << cnt << " " << station << endl;
//			}
//		}
//			
//	}
//}