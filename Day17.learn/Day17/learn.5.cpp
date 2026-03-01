//#include<iostream>
//#include<cstring>
//using namespace std;
//
//template<class nT,class aT>
//class person {
//public:
//	nT name;
//	aT age;
//	person(nT n, aT a) {
//		name = n;
//		age = a;
//	}
//	void show() {
//		cout << "name:" << name << endl;
//		cout << "age:" << age << endl;
//	}
//};
//
//void print1(person<string,int> &a) {
//	a.show();
//}
//
//template<class T1,class T2>
//void print2(person<T1 ,T2>& a) {
//	a.show();
//}
//
//template<class T>
//void print3(T &a) {
//	a.show();
//}
//
//int main()
//{
//	person <string,int>a("Joker", 250);
//	person <string,int>b("King", 300);
//	print1(a);
//	print2(b);
//	print3(a);
//	return 0;
//}