//#include<iostream>
//using namespace std;
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		int** arr = new int* [n];
//		for (int i = 0; i < n; i++) {
//			arr[i] = new int [n];
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//		bool* visited = new bool[n];
//		for (int i = 0; i < n; i++) {
//			visited[i] = false;
//		}
//
//		for (int k = 0; k < n; k++) {
//			int min = 1000000;
//			int min_i = -1;
//			for (int i = 0; i < n; i++) {
//				int cnt = 0;
//				if (visited[i] == false) {
//					for (int j = 0; j < n; j++) {
//						cnt += arr[j][i];
//					}
//					if (cnt < min) {
//						min = cnt;
//						min_i = i;
//					}
//				}
//			}
//			visited[min_i] = true;
//			for (int i = 0; i < n; i++) {
//				arr[min_i][i] = 0;
//			}
//			cout << min_i << " ";
//		}
//		cout << endl;
//	}
//}