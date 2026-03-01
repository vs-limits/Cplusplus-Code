//#include<iostream>
//#include<cstring>
//using namespace std;
//
//template<class T>
//class base {
//protected:
//	T m;
//public:
//
//};
//
//template<class T1,class T2>
//class son :public base<T2> {
//	T1 objl;
//};
//
//template<class T1,class T2>
//class person {
//public:
//	T1 name;
//	T2 age;
//	person(T1 n, T2 a);
//	void show();
//};
//	
//
//template<class T1,class T2>
//person<T1, T2>::person(T1 n, T2 a) {
//	name = n;
//	age = a;
//}
//
//template<class T1, class T2>
//void person<T1,T2>::show(){
//	cout << "name:" << name << " " << "age:" << age << endl;
//}
//
//int main()
//{
//	person<string, int> p("king", 29);
//	p.show();
//	return 0;
//}