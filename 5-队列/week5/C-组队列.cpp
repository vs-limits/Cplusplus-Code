#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main() {
	int t;
	cin >> t;

	unordered_map<int, int> EleminGroup;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int x;
			cin >> x;
			EleminGroup[x] = i;
		}
	}

	queue<int> myQ[10];
	queue<int> Grouporder;
	int* GroupinQ = new int[10];
	for (int i = 0; i < t; i++) GroupinQ[i] = i;
	for (int i = t; i < 10; i++) GroupinQ[i] = 0;
	string op;
	cin >> op;
	while (cin >>op && op != "STOP") {
		if (op == "ENQUEUE") {
			int x;
			cin >> x;
			int group = EleminGroup[x];

			if(group != GroupinQ[group]) {
				Grouporder.push(group);
				GroupinQ[group] = group;
				myQ[group].push(x);
			}
			else if (group == GroupinQ[group]) {
				myQ[group].push(x);
			}
		}
		else if (op == "DEQUEUE") {
			int group = Grouporder.front();
			int x = myQ[group].front();
			cout << x << " ";
			myQ[group].pop();

			if (myQ[group].empty()) {
				Grouporder.pop();
				GroupinQ[group] = 0;
			}
		}
		cin >> op;	
	}
	return 0;
}