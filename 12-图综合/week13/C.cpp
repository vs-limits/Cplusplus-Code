#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int** Mix = new int* [n];
	for(int i = 0; i < n; i++) {
		Mix[i] = new int[n];
	}
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Mix[i][j] = INT32_MAX;
		}
	}
	while (m--) {
		int start, end, weight;
		cin >> start >> end;
		cin >> weight;
		if(weight < Mix[start - 1][end - 1]) {
			Mix[start - 1][end - 1] = weight;
			Mix[end - 1][start - 1] = weight;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(Mix[i][j] == INT32_MAX) {
				Mix[i][j] = 0;
			}
		}
	}

	int* points = new int[n];
	points[0] = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			continue;
		}
		else {
			points[i]= INT32_MAX;
		}
	}

	for (int k = 0; k < n - 1; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Mix[i][j] != 0 && points[i] != INT32_MAX) {
					if (points[j] > Mix[i][j] + points[i]) {
						points[j] = Mix[i][j] + points[i];
					}
				}
			}
		}
	}

	cout << points[n - 1] << endl;
}