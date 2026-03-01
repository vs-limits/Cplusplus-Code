#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	char type;
	string* point;
	int p_num, e_num;
	while (t--) {
		cin >> type;
		cin >> p_num;
		point = new string[p_num];
		for(int i = 0; i < p_num; i++) {
			cin >> point[i];
		}
		cin >> e_num;
		int** Mix = new int* [p_num];
		for (int i = 0; i < p_num; i++) {
			Mix[i] = new int[p_num];
		}
		for (int i = 0; i < p_num; i++) {
			for (int j = 0; j < p_num; j++) {
				Mix[i][j] = 0;
			}
		}
		if (type == 'D') {
			while (e_num--) {
				string start, end;
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

			for(int i = 0; i < p_num; i++) {
				for (int j = 0; j < p_num; j++) {
					cout << Mix[i][j];
					if (j != p_num - 1) {
						cout << " ";
					}
				}
				cout << endl;
			}

			for (int k = 0; k < p_num; k++) {
				int in = 0, out = 0, all = 0;
				for (int i = 0; i < p_num; i++) {
					if (Mix[k][i] == 1) out++;
				}
				for(int i = 0; i < p_num; i++) {
					if (Mix[i][k] == 1) in++;
				}
				all = in + out;
				if (all != 0) {
					cout << point[k] << ": " << out << " " << in << " " << all << endl;
				}
				else {
					cout << point[k] << endl;
				}
			}
		}else if(type == 'U') {
			while (e_num--) {
				string start, end;
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
					Mix[e_index][s_index] = 1;
				}
			}

			for (int i = 0; i < p_num; i++) {
				for (int j = 0; j < p_num; j++) {
					cout << Mix[i][j];
					if (j != p_num - 1) {
						cout << " ";
					}
				}
				cout << endl;
			}

			for (int k = 0; k < p_num; k++) {
				int out = 0;
				for (int i = 0; i < p_num; i++) {
					if (Mix[k][i] == 1) out++;
				}
				if (out != 0) {
					cout << point[k] << ": " << out << endl;
				}
				else {
					cout << point[k] << endl;
				}
			}
		}
	}
	return 0;
}