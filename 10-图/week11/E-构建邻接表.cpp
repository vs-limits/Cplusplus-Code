#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int p_num, e_num;
		cin >> p_num >> e_num;

		char* point = new char[p_num];
		for (int i = 0; i < p_num; i++) {
			cin >> point[i];
		}

		int** Mix = new int* [p_num];
		for (int i = 0; i < p_num; i++) {
			Mix[i] = new int[p_num];
		}
		for (int i = 0; i < p_num; i++) {
			for (int j = 0; j < p_num; j++) {
				Mix[i][j] = 0;
			}
		}

		while (e_num--) {
			char start, end;
			cin >> start >> end;
			int s_index = -1, e_index = -1;
			for (int i = 0; i < p_num; i++) {
				if (point[i] == start) {
					s_index = i;
				}
				if (point[i] == end) {
					e_index = i;
				}
			}
			if (s_index != -1 && e_index != -1) {
				Mix[s_index][e_index] = 1;
			}
		}

		for (int i = 0; i < p_num; i++) {
			cout << i << " " << point[i] << "-";
			for (int j = 0; j < p_num; j++) {
				if (Mix[i][j] == 1) {
					cout << j << "-";
				}
			}
			cout << "^" << endl;
		}
	}
	return 0;
}