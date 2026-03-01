#include<iostream>
using namespace std;

void DFS(int** matrix, int num, int start, bool* visited) {
	visited[start] = true;
	cout << start << " ";
	for(int i = 0; i < num; i++) {
		if(matrix[start][i] == 1 && !visited[i]) {
			DFS(matrix, num, i, visited);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
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
        
		bool* visited = new bool[num];
		for (int j = 0; j < num; j++) {
			visited[j] = false;
		}
		for (int i = 0; i < num; i++) {
			if (visited[i] == false) DFS(matrix, num, i, visited);
		}
		cout << endl;
		delete[] visited;
	}
	return 0;
}