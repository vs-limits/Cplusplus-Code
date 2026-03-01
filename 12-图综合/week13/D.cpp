#include<iostream>
using namespace std;

void DFS(int** matrix, int num, int start, int current, bool*& visited) {
	visited[current] = true;
	matrix[start][current] = 1;

	for (int i = 0; i < num; i++) {
		if (matrix[current][i] && !visited[i]) {
			DFS(matrix, num, start, i, visited);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int** Mix = new int* [n];
	for (int i = 0; i < n; i++) {
		Mix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Mix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		bool* visited = new bool[n];
		for (int j = 0; j < n; j++) {
			visited[j] = false;
		}
		DFS(Mix, n, i, i, visited);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && Mix[i][j] && Mix[j][i]) {
				Mix[i][i] = 1;
			}
			else {
				Mix[i][i] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Mix[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] Mix[i];
	}
	delete[] Mix;

	return 0;
}
