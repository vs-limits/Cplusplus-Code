//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//class Shape {
//public:
//	virtual void area() = 0;
//};
//
//class Circle :public Shape {
//	double r;
//public:
//	Circle(double r1) :r(r1) {}
//	void area() {
//		cout << fixed << setprecision(2) << 3.14 * r * r << endl;
//	}
//};
//
//class Rectangle :public Shape {
//	double l;
//	double wide;
//public:
//	Rectangle(double l1, double w) :l(l1), wide(w) {}
//	void area() {
//		cout << fixed << setprecision(2) << l * wide << endl;;
//	}
//};
//
//class Square :public Shape {
//	double side;
//public:
//	Square(double s):side(s){}
//	void area() {
//		cout << fixed << setprecision(2) << side * side << endl;
//	}
//};
//int main()
//{
//	int t;
//	double r, l, w, s;
//	Shape* shape;
//	cin >> t;
//	while (t--) {
//		cin >> r >> s >> l >> w;
//		Shape* shape[3] = {
//			new Circle(r),
//			new Square(s),
//			new Rectangle(l, w),
//		};
//		for (int j = 0; j < 3; j++) {
//			shape[j]->area();
//		}
//		for (int j = 0; j < 3; j++) {
//			delete shape[j];
//		}
//	}
//	return 0;
//}