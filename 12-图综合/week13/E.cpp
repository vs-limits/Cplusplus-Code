#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int type, rate_num;
		cin >> type >> rate_num;
		string* names = new string[type];
		for(int i = 0; i < type; i++) {
			cin >> names[i];
		}
		double** Mix = new double*[type];
		for(int i = 0; i < type; i++) {
			Mix[i] = new double[type];
		}

		for (int i = 0; i < type; i++) {
			for (int j = 0; j < type; j++) {
				Mix[i][j] = 1.0;
			}
		}

		for (int i = 0; i < rate_num; i++) {
			string start, end;
			double rate;
			cin >> start >> rate >> end;
			int start_index, end_index;
			for(int j = 0; j < type; j++) {
				if(names[j] == start) {
					start_index = j;
				}
				if(names[j] == end) {
					end_index = j;
				}
			}
			Mix[start_index][end_index] = rate;
		}

		double* money = new double[type];
		money[0] = 1.0;
		for (int i = 1; i < type; i++) {
			money[i] = 0.0;
		}
		for (int k = 0; k < type - 1; k++) {
			for (int j = 0; j < type; j++) {
				for (int i = 0; i < type; i++) {
					if (money[i] < money[j] * Mix[i][j]) {
						money[i] = money[j] * Mix[i][j];
					}
				}
			}
		}

		if(money[0] > 1.0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

}