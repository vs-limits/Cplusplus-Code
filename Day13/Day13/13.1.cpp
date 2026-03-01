//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//class shape {
//private:
//public:
//	virtual void area()= 0;
//};
//
//class circle : public shape {
//private:
//	double radius;
//public:
//	circle(double r) :radius(r) {};
//	void area() {
//		cout << fixed << setprecision(2) << 3.14 * radius * radius << endl;
//	}
//};
//
//class square :public shape {
//private:
//	double side;
//public:
//	square(double s) :side(s) {};
//	void area() {
//		cout << fixed << setprecision(2) << side * side << endl;
//	}
//};
//
//class rectangle :public shape {
//private:
//	double longth;
//	double width;
//public:
//	rectangle(double l,double w) :longth(l), width(w) {};
//	void area() {
//		cout << fixed << setprecision(2) <<  longth * width << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	double r, s, l, w;
//	shape* obj;
//	while (t--) {
//		cin >> r >> s >> l >> w;
//		shape* obj[3] = {
//			new circle(r),
//			new square(s),
//			new rectangle(l,w),
//		};
//		for (int i = 0; i < 3; i++) {
//			obj[i]->area();
//		}
//		for (int i = 0; i < 3; i++) {
//			delete obj[i];
//		}
//	}
//	return 0;
//}