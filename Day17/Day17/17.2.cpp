//#include<iostream>
//using namespace std;
//
//template<class T1>
//class Matrix {
//protected:
//	T1** matrix;
//	int m, n;
//public:
//	Matrix(T1** arr, int mm, int nn) {
//        m = mm;
//		n = nn;
//		matrix = new T1*[m];
//		for (int i = 0; i < m; i++) {
//			matrix[i] = new T1[n];
//			for (int j = 0; j < n; j++) {
//				matrix[i][j] = arr[i][j];
//			}
//		}
//
//	}
//	Matrix transport() {
//		T1** data;
//		data = new T1*[n];
//		for (int i = 0; i < n; i++) {
//			data[i] = new T1[m];
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << i << "  " << j << endl;
//				data[i][j] = matrix[j][i];
//			}
//		}
//		Matrix<T1> temp(data, n, m);
//		return temp;
//	}
//	void print() {
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << matrix[i][j];
//				if (j != n - 1) {
//					cout << " ";
//				}
//			}
//			cout << endl;
//		}
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	char tp;
//	int m, n;
//	while (t--) {
//		cin >> tp >> m >> n;
//		if (tp == 'I') {
//			int** arr = new int*[m];
//			for (int i = 0; i < m; i++) {
//				arr[i] = new int[n];
//				for (int j = 0; j < n; j++) {
//					cin >> arr[i][j];
//				}
//			}
//			Matrix<int> obj(arr, m, n);
//			Matrix<int> obj2 = obj.transport();
//			obj2.print();
//		}
//		else if (tp == 'D') {
//			double** arr = new double* [m];
//			for (int i = 0; i < m; i++) {
//				arr[i] = new double[n];
//				for (int j = 0; j < n; j++) {
//					cin >> arr[i][j];
//				}
//			}
//			Matrix<double> obj(arr, m, n);
//			Matrix<double> obj2 = obj.transport();
//			obj2.print();
//		}
//		else if (tp == 'C') {
//			char** arr = new char* [m];
//			for (int i = 0; i < m; i++) {
//				arr[i] = new char[n];
//				for (int j = 0; j < n; j++) {
//					cin >> arr[i][j];
//				}
//			}
//			Matrix<char> obj(arr, m, n);
//			Matrix<char> obj2 = obj.transport();
//			obj2.print();
//		}
//	}
//	return 0;
//}