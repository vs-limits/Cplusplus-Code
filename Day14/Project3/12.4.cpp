#include<iostream>
using namespace std;

class MyMatrix {
private:
	int n;
	int **data;
public:
	MyMatrix(){}
	MyMatrix(int N,int **d) {
		n = N;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = d[i][j];
			}
		}
	}
	~MyMatrix() { for (int i = 0; i < n; i++) { delete[] data[i]; } delete[] data; }
	MyMatrix operator * (MyMatrix& m2) {
		MyMatrix m_t;
		m_t.n = n;
		m_t.data = new int* [n];
		for (int i = 0; i < n; i++) {
			m_t.data[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				m_t.data[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					m_t.data[i][j] += this->data[i][k] * m2.data[k][j];
				}
			}
		}
		return m_t;
	}
	void show() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << data[i][j];
				if (j != n - 1) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	void set(int nn) {
		n = nn;
		data = new int* [n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> data[i][j];
			}
		}
	}
	MyMatrix(const MyMatrix &m):n(m.n) {
		data = new int* [n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
};

int main()
{
	int t,n;
	cin >> t >> n;
	MyMatrix *m = new MyMatrix[t];
	for (int i = 0; i < t; i++) {
		m[i].set(n);
	}
	MyMatrix *m3 = &m[0];
	for (int i = 1; i < t; i++) {
		m3 = new MyMatrix(*m3 * m[i]);
	}
	m3->show();
	return 0;
}