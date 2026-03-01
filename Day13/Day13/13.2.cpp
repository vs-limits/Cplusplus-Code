//#include<iostream>
//using namespace std;
//
//class vehicle {
//protected:
//	string no;
//public:
//	vehicle(string n) :no(n) {};
//	virtual void display() = 0;
//};
//
//class car : public vehicle {
//protected:
//	int num;
//	int weight;
//public:
//	car(string no,int n, int w) :vehicle(no),num(n), weight(w) {};
//	void display() {
//		cout << no << " " << (num * 8 + weight * 2) << endl;
//	}
//};
//
//class truck : public vehicle {
//protected:
//	int weight;
//public:
//	truck(string no,int w) :vehicle(no),weight(w) {};
//	void display() {
//		cout << no << " " << weight * 5 << endl;
//	}
//};
//
//class bus : public vehicle {
//protected:
//	int num;
//public:
//	bus(string no,int n) :vehicle(no),num(n) {};
//	void display() {
//		cout << no << " " << num * 30 << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int type;
//	vehicle* v;
//	while (t--) {
//		string no;
//		int num, weight;
//		cin >> type;
//		if (type == 1) {
//			cin >> no >> num >> weight;
//			vehicle* v = new car(no, num, weight);
//			v->display();
//		}
//		else if (type == 2) {
//			cin >> no >> weight;
//			vehicle* v = new truck(no, weight);
//			v->display();
//		}
//		else if (type == 3) {
//			cin >> no >> num;
//			vehicle* v = new bus(no, num);
//			v->display();
//		}
//	}
//	return 0;
//}