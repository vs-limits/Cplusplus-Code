//#include<iostream>
//using namespace std;
//
//class point {
//private:
//	int x, y, z;
//public:
//	point(int X, int Y, int Z) :x(X),y(Y),z(Z){};
//	friend point operator ++(point& a) {//«∞÷√
//		a.x++;
//		a.y++;
//		a.z++;
//		return a;
//	};
//	friend point operator ++(point &a, int) {//∫Û÷√
//		point temp(a);
//		a.x++;
//		a.y++;
//		a.z++;
//		return temp;
//	};
//	friend point operator --(point& a) {
//		a.x--;
//		a.y--;
//		a.z--;
//		return a;
//	};
//	friend point operator --(point &a, int) {
//		point temp(a);
//		a.x--;
//		a.y--;
//		a.z--;
//		return temp;
//	};
//	void show() {
//		cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl;
//	};
//};
//
//int main()
//{
//	int x, y, z;
//	cin >> x >> y >> z;
//	point p1(x,y,z),p0(x,y,z);
//	point p2 = p1++;
//	p1.show();
//	p2.show();
//	p1 = p0;
//	p2 = ++p1;
//	p1.show();
//	p2.show();
//	p1 = p0;
//	p2 = p1--;
//	p1.show();
//	p2.show();
//	p1 = p0;
//	p2 = --p1;
//	p1.show();
//	p2.show();
//	return 0;
//}