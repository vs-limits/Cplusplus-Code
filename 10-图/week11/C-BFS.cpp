#include<iostream>
#include<queue>
using namespace std;

void BFS(int** matrix, int num, int start, bool* visited) {
	queue<int> q;
	visited[start] = true;
	cout << start << " ";
	for (int i = 0; i < num; i++) {
		if (matrix[start][i] == 1 && !visited[i]) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		if (!visited[curr]) {
			visited[curr] = true;
			cout << curr << " ";
			for (int i = 0; i < num; i++) {
				if (matrix[curr][i] == 1 && !visited[i]) {
					q.push(i);
				}
			}
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
			if (visited[i] == false) BFS(matrix, num, i, visited);
		}
		cout << endl;
		delete[] visited;
	}
	return 0;
}