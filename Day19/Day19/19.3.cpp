//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int p[] = { 5,5,5,51,55,5,5,0,0,0 };
//double w[] = { 0,0,0,0,0,0.45,2.0,3,25,35 };
//int r[] = { 800,400,800,1300,1500,500,450,200,1500,2000 };
//
//
//class result {
//private:
//	int person;
//	double weight;
//	int rent;
//public:
//	result() :person(0), weight(0), rent(0) {};
//	void sum(int n) {
//		person += p[n-1];
//		weight += w[n - 1];
//		rent += r[n - 1];
//	}
//	void show() {
//		cout << person << " " << fixed << setprecision(2) << weight << " " << rent << endl;
//	}
//};
//
//int main()
//{
//	int flag;
//	cin >> flag;
//	result obj;
//	if (flag == 0) {
//		cout << "0 0.00 0" << endl;
//	}
//	else if (flag == 1) {
//		int num;
//		cin >> num;
//		while (num--) {
//			int tp, day;
//			cin >> tp >> day;
//			while (day--) {
//				obj.sum(tp);
//			}
//		}
//		obj.show();
//	}
//}