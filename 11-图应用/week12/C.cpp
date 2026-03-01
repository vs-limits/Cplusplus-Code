#include<iostream>
using namespace std;

struct edge {
	int start;
	int end;
};

int findParent(int* parent, int i) {
	if (parent[i] != i) {
		parent[i] = findParent(parent, parent[i]);
	}
	return parent[i];
}

void uni(int* parent, int x, int y,int& cnt) {
	int xroot = findParent(parent, x - 1);
	int yroot = findParent(parent, y - 1);

	if (xroot != yroot) {
		parent[xroot] = yroot;
		cnt++;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		edge* edges = new edge[n];
		for (int i = 0; i < n; i++) {
			cin >> edges[i].start >> edges[i].end;
		}

		int* parent = new int[n + 1];
		for (int i = n - 1; i >= 0; i--) {
			int cnt = 0;
			for (int k = 0; k < n; k++) parent[k] = k;

			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				int u = edges[j].start;
				int v = edges[j].end;
				uni(parent,u, v, cnt);
			}

			if (cnt == n - 1) {
				cout << edges[i].start << " " << edges[i].end;
				break;
			}
		}
		cout << endl;
		delete[] edges;
		delete[] parent;
	}
	return 0;
}