#include<iostream>
using namespace std;

class CMatrix;

class CVector {
private:
	int* data;
	int n;
public:
	CVector() {
		n = 5;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = i;
		}
	}
	CVector(int nn,int *d) {
		n = nn;
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = d[i];
		}
	}
	void show() {
		for (int i = 0; i < n; i++) {
			cout << data[i];
			if (i != n - 1) {
				cout << " ";
			}
		}
	}
	friend class CMatrix;
};

class CMatrix {
private:
	int n;
	int** data;
public:
	CMatrix() {
		n = 0;
	}
	CMatrix(int nn, int** d) {
		n = nn;
		data = new int*[n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> data[i][j];
			}
		}
	}
	bool canMulti(const CVector &v1) {
		if (n == v1.n) return true;
		else { return false; }
	}
	CVector multi(const CVector& v1) {
		CVector result(v1.n,v1.data);
		for (int i = 0; i < n; i++) {
			result.data[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result.data[i] += v1.data[j] * data[i][j];
			}
		}
		return result;
	}
};

int main()
{
	int t,n,m;
	cin >> t;
	while (t--) {
		cin >> n;
		int** d = new int*[n];
		for (int i = 0; i < n; i++) {
			d[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> d[i][j];
			}
		}
		CMatrix M(n,d);
		cin >> m;
		int* d1 = new int[m];
		for (int i = 0; i < m; i++) {
			cin >> d1[i];
		}
		CVector V(m, d1);
		if (M.canMulti(V)) {
			CVector v2 = M.multi(V);
			v2.show();
		}
		else if (!M.canMulti(V)) {
			cout << "error" << endl;
		}
	}
	return 0;
}