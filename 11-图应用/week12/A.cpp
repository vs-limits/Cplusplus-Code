//#include<iostream>
//using namespace std;
//
//void DFS(int** matrix, int num, int start, bool* visited) {
//	visited[start] = true;
//	for (int i = 0; i < num; i++) {
//		if (matrix[start][i] == 1 && !visited[i]) {
//			DFS(matrix, num, i, visited);
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int p_num;
//		cin >> p_num;
//		string* point = new string[p_num + 1];
//		for (int i = 0; i < p_num; i++) {
//			cin >> point[i];
//		}
//
//		int** Mix = new int* [p_num];
//		for (int i = 0; i < p_num; i++) {
//			Mix[i] = new int[p_num];
//		}
//		for (int i = 0; i < p_num; i++) {
//			for (int j = 0; j < p_num; j++) {
//				Mix[i][j] = 0;
//			}
//		}
//
//		int e_num;
//		cin >> e_num;
//		for (int i = 0; i < e_num; i++) {
//			string start, end;
//			cin >> start >> end;
//			int s_index = -1, e_index = -1;
//			for (int i = 0; i < p_num; i++) {
//				if (point[i] == start) {
//					s_index = i;
//				}
//				if (point[i] == end) {
//					e_index = i;
//				}
//			}
//			if (s_index != -1 && e_index != -1) {
//				Mix[s_index][e_index] = 1;
//				Mix[e_index][s_index] = 1;
//			}
//		}
//
//		for (int i = 0; i < p_num; i++) {
//			cout << point[i];
//			if (i != p_num - 1) cout << " ";
//		}
//		cout << endl;
//
//		for (int i = 0; i < p_num; i++) {
//			for (int j = 0; j < p_num; j++) {
//				cout << Mix[i][j];
//				if (j != p_num - 1) cout << " ";
//			}
//			cout << endl;
//		}
//
//		bool* visited = new bool[p_num];
//		for (int j = 0; j < p_num; j++) {
//			visited[j] = false;
//		}
//		int count = 0;
//		for (int i = 0; i < p_num; i++) {
//			if (visited[i] == false) {
//				DFS(Mix, p_num, i, visited);
//				count++;
//			}
//			
//		}
//		cout << count << endl;
//		cout << endl;
//		delete[] visited;
//	}
//}