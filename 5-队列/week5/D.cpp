#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ALL = 0;
	double avg = 0;
	int max = 0;
	queue<int> wait;
	queue<int> Wtime;
	queue<int> Rtime;
	for (int i = 0; i < n; i++) {
		int W, R;
		cin >> W >> R;
		Wtime.push(W);
		Rtime.push(R);
	}
	int k;
	cin >> k;
	int* run = new int[k];
	for (int i = 0; i < k; i++) run[i] = 0;
	int cnt = 0;
	while (!Wtime.empty() && !Rtime.empty()) {
		int r_min = 10000;
		for (int i = 0; i < k; i++) {
			if (run[i] < r_min) {
				r_min = run[i];
			}
		}
		if (Wtime.front() == 0) {
			run[cnt] = Rtime.front();
			Wtime.pop();
			Rtime.pop();
			cnt = (cnt + 1) % k;
		}
		else if (Wtime.front() > 0 && Wtime.front() < r_min) {

		}
	}

}