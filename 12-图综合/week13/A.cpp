//#include<iostream>
//using namespace std;
//
//void DFS(int** matrix, int num, int start,int& cnt,int round) {
//	if (round == 0) {
//		if (start == num - 1) {
//			cnt += 1;
//		}
//		return;
//	}
//
//	for (int i = 0; i < num; i++) {
//		if (matrix[start][i]) {
//			DFS(matrix, num, i, cnt ,round - 1);
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, len;
//		cin >> n >> len;
//		int** Mix = new int* [n];
//		for (int i = 0; i < n; i++) {
//			Mix[i] = new int[n];
//		}
//		for(int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				Mix[i][j] = 0;
//			}
//		}
//
//		for (int i = 0; i < len; i++) {
//			int start, end;
//			cin >> start >> end;
//			Mix[start][end] = 1;
//		}
//
//		int round;
//		cin >> round;
//
//		int cnt = 0;
//		DFS(Mix, n, 0, cnt ,round);
//
//		cout << cnt << endl;
//	}
//}