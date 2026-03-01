#include<iostream>
using namespace std;

struct prerequest {
	int course;
	int pre;
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int len;
		cin >> n >> len;
		int** Mix = new int* [n];
		for (int i = 0; i < n; i++) {
			Mix[i] = new int[n];
		}
		for(int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Mix[i][j] = 0;
			}
		}

		bool* visited = new bool[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}

		prerequest* arr = new prerequest[len];
		for (int i = 0; i < len; i++) {
			cin >> arr[i].course >> arr[i].pre;
		}

		for(int i = 0; i < len; i++) {
			Mix[arr[i].pre][arr[i].course] = 1;
		}

		int min = 1000000;
		for (int k = 0; k < n; k++) {
			min = 1000000;
			int min_i = -1;
			for (int i = 0; i < n; i++) {
				int cnt = 0;
				if (visited[i] == false) {
					for (int j = 0; j < n; j++) {
						cnt += Mix[j][i];
					}
					if (cnt < min) {
						min = cnt;
						min_i = i;
					}
				}
			}
			if (min != 0) {
				break;
			}
			else {
				visited[min_i] = true;
				for (int i = 0; i < n; i++) {
					Mix[min_i][i] = 0;
				}
			}
		}
		if (min == 0) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}