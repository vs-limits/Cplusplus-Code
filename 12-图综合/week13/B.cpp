#include<iostream>

struct point {
	int weight;
	int pre;
};

using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
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

		int v0;
		cin >> v0;

		point* points = new point[n];
		points[v0].weight = 0;
		points[v0].pre = -1;
		for (int i = 0; i < n; i++) {
			if (i == v0) { 
				continue; 
			}
			else {
				points[i].weight = INT32_MAX;
				points[i].pre = -1;
			}
		}

		for (int k = 0; k < n - 1; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (Mix[i][j] != 0 && points[i].weight != INT32_MAX) {
						if (points[j].weight > Mix[i][j] + points[i].weight) {
							points[j].weight = Mix[i][j] + points[i].weight;
							points[j].pre = i;
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (i == v0) {
				continue;
			}
			else {
				cout << v0 << "-" << i << "-" << points[i].weight << "----[";
				int* path = new int[n];
				int k = 0;
				int temp = i;
				while (points[temp].pre != -1) {
					path[k] = temp;
					temp = points[temp].pre;
					k++;
				}
				path[k] = v0;
				for (int j = k; j >= 0; j--) {
					cout << path[j] << " ";
				}
				cout << "]" << endl;
			}
			
		}
	}
}