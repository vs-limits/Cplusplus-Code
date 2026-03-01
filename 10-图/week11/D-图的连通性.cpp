#include<iostream>
using namespace std;

void DFS(int** matrix, int num, int start, bool* visited) {
	visited[start] = true;
	for(int i = 0; i < num; i++) {
		if(matrix[start][i] == 1 && !visited[i]) {
			DFS(matrix, num, i, visited);
		}
	}
}
int main() {
	int k;
	cin >> k;
	while (k--) {
		int num;
		cin >> num;
		int** matrix = new int* [num];
		for (int i = 0; i < num; i++) {
			matrix[i] = new int[num];
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cin >> matrix[i][j];
			}
		}

		int flag = 0;
		for (int q = 0; q < num; q++) {
			bool* visited = new bool[num];
			for (int j = 0; j < num; j++) {
				visited[j] = false;
			}

			for (int i = q; i < num; i++) {
				if (visited[i] == false) DFS(matrix, num, i, visited);
			}

			for (int j = 0; j < num; j++) {
				if (visited[j] == false) {
					flag = 1;
					break;
				}
			}

			if (flag == 1) {
				cout << "No" << endl;
				break;
			}

			delete[] visited;
		}
		if (flag == 0) {
			cout << "Yes" << endl;
		}

	}
	return 0;
}