//#include<iostream>
//using namespace std;
//
//class metal {
//protected:
//	int hardness;
//	int weight;
//	int volumn;
//public:
//	metal() : hardness(0), weight(0), volumn(0) {};
//	metal(int h,int w,int v) : hardness(h), weight(w), volumn(v) {};
//	metal friend operator +(metal &m1,metal &m2) {
//		int t_h = m1.hardness + m2.hardness;
//		int t_w = m1.weight + m2.weight;
//		int t_v = m1.volumn + m2.volumn;
//		metal temp(t_h, t_w, t_v);
//		return temp;
//	}
//	metal friend operator *(metal& m1, int n) {
//		int t_v = m1.volumn * n;
//		int t_h = m1.hardness;
//		int t_w = m1.weight;
//		metal temp(t_h, t_w, t_v);
//		return temp;
//	}
//	metal friend operator ++(metal &m1) {
//		m1.hardness += 1;
//		m1.weight += m1.weight * 0.1;
//		m1.volumn += m1.volumn * 0.1;
//		return m1;
//	}
//	metal friend operator --(metal& m1, int) {
//		metal temp = m1;
//		m1.hardness -= 1;
//		m1.weight -= m1.weight * 0.1;
//		m1.volumn -= m1.volumn * 0.1;
//		return m1;
//	}
//	void print() {
//		cout << "硬度" << hardness << "--重量" << weight << "--体积" << volumn << endl;
//	}
//};
//
//int main()
//{
//	int h1, h2, w1, w2, v1, v2;
//	int n;
//	cin >> h1 >> w1 >> v1;
//	cin >> h2 >> w2 >> v2;
//	cin >> n;
//	metal m1(h1, w1, v1);
//	metal m2(h2, w2, v2);
//	metal mt = m1 + m2;
//	mt.print();
//	mt = m1 * n;
//	mt.print();
//	mt = ++m1;
//	mt.print();
//	mt = m2--;
//	mt.print();
//	return 0;
//}