//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Point
//{
//private:
//	double x, y;
//public:
//	Point(double xx, double yy) {
//		x = xx;
//		y = yy;
//	}
//	friend int distance(Point& a, Point& b);
//};
//
//int distance(Point& a, Point& b) {
//	double dx = a.x - b.x;
//	double dy = a.y - b.y;
//	int dis = sqrt(dx * dx + dy * dy);
//	return dis;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	int x1, y1, x2, y2;
//	while (t--) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		Point a(x1, y1), b(x2, y2);
//		cout << distance(a, b) << endl;
//	}
//	return 0;
//}