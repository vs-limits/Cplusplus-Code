#include<iostream>
using namespace std;

class Cmatrix {
private:
	int n;
	int m;
	int** data;
public:
	Cmatrix() {};
	Cmatrix(int nn, int mm){
		n = nn;
		m = mm;
		data = new int*[n];
		for (int i = 0; i < n; i++) {
			data[i] = new int[m];
		}
	};
	~Cmatrix() {
		for (int i = 0; i < n; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
    friend istream & operator >>(istream & in, Cmatrix &c) {
        for (int i = 0; i < c.n; i++) {
            for (int j = 0; j < c.m; j++) {
                in >> c.data[i][j];
            }
        }
        return in;
    }
    Cmatrix operator =(const Cmatrix& c1) {
        this->n = c1.n;
        this->m = c1.m;
        this->data = new int* [n];
        for (int i = 0; i < n; i++) {
            data[i] = new int[m];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->data[i][j] = c1.data[i][j];
            }
        }
        return *this;
    }
    friend ostream& operator <<(ostream& out, Cmatrix& c) {
        for (int i = 0; i < c.n; i++) {
            for (int j = 0; j < c.m; j++) {
                out << c.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
    int* operator[](int i) {
        return data[i];
    }
};

int main()
{
    int t, n, m, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        Cmatrix matrixA(n, m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                // �����i�е�j�е�����
                cin >> matrixA[i][j];
            }
        }
        // ���matrixA�е�����
        cout << "matrixA:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << matrixA[i][j]<< " ";
            }
            cout << endl;
        }
        // ����������matrixB
        Cmatrix matrixB;
        matrixB = matrixA;
        // ���marixB�е�����
        cout << "matrixB:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << matrixB[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}