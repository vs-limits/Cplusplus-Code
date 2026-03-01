//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class pet {
//protected:
//	string name;
//	int x, y;
//	float radius;
//	int ATK;
//public:
//	pet() :name(0), x(0), y(0), radius(0), ATK(0) {};
//	pet(string n,int xx,int yy,int r,int a) :name(n), x(xx), y(yy), radius(r), ATK(a) {};
//	friend void fight(pet& p1, pet& p2);
//};
//
//void fight(pet& p1, pet& p2) {
//	double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
//	int actual1;
//	int actual2;
//	if (distance > p1.radius) actual1 = 0;
//	else if(distance <= p1.radius) actual1 = (p1.radius / distance) * p1.ATK;
//	if (distance > p2.radius) actual2 = 0;
//	else if(distance <= p2.radius) actual2 = (p2.radius / distance) * p2.ATK;
//	if (actual1 > actual2) cout << p1.name << " wins !" << endl;
//	else if (actual1 < actual2) cout << p2.name << " wins !" << endl;
//	else if (actual1 == actual2) cout << "The two sides drew !" << endl;
//
//	/*if (distance > p1.radius && distance > p2.radius) {
//		cout << "The two sides drew !" << endl;
//	}
//	else if (distance > p1.radius && distance < p2.radius) {
//		cout << p2.name << " wins !" << endl;
//	}
//	else if (distance < p1.radius && distance > p2.radius) {
//		cout << p1.name << " wins !" << endl;
//	}
//	else if (distance < p1.radius && distance < p2.radius) {
//		int actual1 = (p1.radius / distance) * p1.ATK;
//		int actual2 = (p2.radius / distance) * p2.ATK;
//		if(actual1 > actual2) cout << p1.name << " wins !" << endl;
//		else if(actual1 < actual2) cout << p2.name << " wins !" << endl;
//		else if(actual1 == actual2) cout << "The two sides drew !" << endl;
//	}*/
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string n1, n2;
//	int x1, y1, x2, y2;
//	float r1, r2;
//	int A1, A2;
//	while (t--) {
//		cin >> n1 >> x1 >> y1 >> r1 >> A1;
//		cin >> n2 >> x2 >> y2 >> r2 >> A2;
//		pet p1(n1, x1, y1, r1, A1);
//		pet p2(n2, x2, y2, r2, A2);
//		fight(p1, p2);
//	}
//}