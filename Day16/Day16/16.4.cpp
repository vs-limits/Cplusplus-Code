//#include<iostream>
//using namespace std;
//
//class CSet {
//private:
//	int n;
//	int* data;
//public:
//	CSet(int nn, int* d) {
//		n = nn;
//		data = new int[n];
//		for (int i = 0; i < n; i++) {
//			data[i] = d[i];
//		}
//	}
//	friend ostream& operator << (ostream& stream, const CSet& s) {
//		for (int i = 0; i < s.n; i++) {
//			stream << s.data[i];
//			if (i != s.n - 1) {
//				stream << " ";
//			}
//			else { stream << endl; }
//		}
//		return stream;
//	}
//	friend CSet operator +(const CSet& s1, const CSet& s2) {
//		int cnt = 0;
//		for (int i = 0; i < s2.n; i++) {
//			for (int j = 0; j < s1.n; j++) {
//				if (s2.data[i] == s1.data[j]) { cnt += 1; break; }
//			}
//		}
//		int n = s1.n + s2.n - cnt;
//		int* d = new int[n];
//		int pos = 0;
//		for (int i = 0; i < s1.n; i++) {
//			d[pos++] = s1.data[i];
//		}
//
//		for (int i = 0; i < s2.n; i++) {
//			int found = 0;
//			for (int j = 0; j < s1.n; j++) {
//				if (s2.data[i] == s1.data[j]) {
//					found = 1;
//					break;
//				}
//			}
//			if (found == 0) {
//				d[pos++] = s2.data[i];
//			}
//		}
//		CSet temp(n, d);
//		delete[] d;
//		return temp;
//	};
//	friend CSet operator *(const CSet& s1, const CSet& s2) {
//		int cnt = 0;
//		for (int i = 0; i < s2.n; i++) {
//			for (int j = 0; j < s1.n; j++) {
//				if (s2.data[i] == s1.data[j]) { cnt += 1; }
//			}
//		}
//		int n = cnt;
//		int* d = new int[n];
//		int num = 0;
//		for (int i = 0; i < s1.n; i++) {
//			for (int j = 0; j < s2.n; j++) {
//				if (s2.data[j] == s1.data[i]) { d[num++] = s1.data[i]; break; }
//			}
//		}
//		CSet temp(n, d);
//		delete[] d;
//		return temp;
//	}
//	friend CSet operator -(const CSet& s1, const CSet& s2) {
//		int cnt = 0;
//		for (int i = 0; i < s2.n; i++) {
//			for (int j = 0; j < s1.n; j++) {
//				if (s2.data[i] == s1.data[j]) { cnt += 1; }
//			}
//		}
//		int n = s1.n - cnt;
//		int* d = new int[n];
//		int num = 0;
//		for (int i = 0; i < s1.n; i++) {
//			int flag = 0;
//			for (int j = 0; j < s2.n; j++) {
//				if (s2.data[j] == s1.data[i]) { flag = 1; break; }
//			}
//			if (flag == 0) {
//				d[num++] = s1.data[i];
//			}
//		}
//		CSet temp(n, d);
//		return temp;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int n1, n2;
//	while (t--) {
//		cin >> n1;
//		int* d1 = new int[n1];
//		for (int i = 0; i < n1; i++) {
//			cin >> d1[i];
//		}
//		CSet s1(n1, d1);
//		cout << "A:" << s1;
//		cin >> n2;
//		int* d2 = new int[n2];
//		for (int i = 0; i < n2; i++) {
//			cin >> d2[i];
//		}
//		CSet s2(n2, d2);
//		cout << "B:" << s2;
//		cout << "A+B:" << s1 + s2;
//		cout << "A*B:" << s1 * s2;
//		cout << "(A-B)+(B-A):" << ((s1 - s2) + (s2 - s1)) << endl;
//	}
//	return 0;
//}