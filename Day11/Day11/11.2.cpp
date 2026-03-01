//#include<iostream>
//using namespace std;
//class Vehicle
//{
//protected:
//	string no;
//public:
//	Vehicle(string n):no(n){}
//	virtual void display() = 0;
//};
//
//class Car :public Vehicle {
//protected:
//	int number;
//	int weight;
//public:
//	Car(string no,int n,int w):Vehicle(no), number(n), weight(w) {}
//	void display() {
//		int sum = number * 8 + weight * 2;
//		cout << no << " " << sum << endl;
//	}
//};
//
//class Truck :public Vehicle {
//protected:
//	int weight;
//public:
//	Truck(string no,int w):Vehicle(no),weight(w){}
//	void display() {
//		int sum = weight * 5;
//		cout << no << " " << sum << endl;
//	}
//};
//
//class Bus :public Vehicle {
//protected:
//	int number;
//public:
//	Bus(string no, int n) :Vehicle(no), number(n) {}
//	void display() {
//		int sum = number * 30;
//		cout << no << " " << sum << endl;
//	}
//};
//
//int main() 
//{
//	int t;
//	cin >> t;
//	int type;
//	string no;
//	int number,weight;
//	Vehicle* pv;
//	while (t--) {
//		cin >> type;
//		if (type == 1) {
//			cin >> no >> number >> weight;
//			pv = new Car(no,number, weight);
//			pv->display();
//		}else if (type == 2) {
//			cin >> no >> weight;
//			pv = new Truck(no, weight);
//			pv->display();
//		}else if (type == 3) {
//			cin >> no >> number;
//			pv = new Bus(no, number);
//			pv->display();
//		}
//	}
//	return 0;
//}