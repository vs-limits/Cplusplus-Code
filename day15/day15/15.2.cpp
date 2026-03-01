//#include<iostream>
//using namespace std;
//
//class CMoney {
//private:
//	int yuan, jiao, fen;
//public:
//	CMoney() :yuan(0), jiao(0), fen(0) {};
//	CMoney(int y, int j, int f) :yuan(y), jiao(j), fen(f) {};
//	friend CMoney operator +(CMoney& m1, CMoney& m2) {
//		CMoney temp;
//		temp.yuan = m1.yuan + m2.yuan;
//		temp.jiao = m1.jiao + m2.jiao;
//		if (temp.jiao >= 10) {
//			temp.jiao -= 10;
//			temp.yuan += 1;
//		}
//		temp.fen = m1.fen + m2.fen;
//		if (temp.fen >= 10) {
//			temp.fen -= 10;
//			temp.jiao += 1;
//		}
//		return temp;
//	};
//	friend CMoney operator -(CMoney& m1, CMoney& m2) {
//		CMoney temp;
//		temp.yuan = m1.yuan - m2.yuan;
//		if (temp.yuan < 0) { temp.yuan = 0; }
//		temp.jiao = m1.jiao - m2.jiao;
//		if (temp.jiao < 0) {
//			if (temp.yuan > 0) {
//				temp.jiao += 10;
//				temp.yuan -= 1;
//			}
//			else {
//				temp.jiao = 0;
//			}
//
//		}
//		temp.fen = m1.fen - m2.fen;
//		if (temp.fen < 0) {
//			if (temp.jiao > 0) {
//				temp.fen += 10;
//				temp.jiao -= 1;
//			}
//			else if (temp.yuan > 0 && temp.jiao == 0) {
//				temp.yuan -= 1;
//				temp.jiao = 9;
//				temp.fen += 10;
//			}
//			else {
//				temp.fen = 0;
//			}
//		}
//
//		return temp;
//	}
//	void show() {
//		cout << yuan << "Ôª" << jiao << "½Ç" << fen << "·Ö" << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int y, j, f;
//	while (t--) {
//		cin >> y >> j >> f;
//		CMoney m1(y, j, f);
//		string op;
//		cin >> op;
//		while (op != "stop") {
//			cin >> y >> j >> f;
//			CMoney m2(y, j, f);
//			if (op == "add") {
//				m1 = m1 + m2;
//			}
//			else if (op == "minus") {
//				m1 = m1 - m2;
//			}
//			cin >> op;
//		}
//		m1.show();
//	}
//	return 0;
//}