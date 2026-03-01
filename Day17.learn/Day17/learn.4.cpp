//#include<iostream>
//using namespace std;
//
//class person {
//public:
//	string name;
//	int age;
//	person(string n, int a) {
//		name = n;
//		age = a;
//	}
//};
//
//template<class T>
//bool compare(T& a, T& b) {
//	if (a == b) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//template<> bool compare(person& a, person& b)
//{
//	if (a.name == b.name && a.age == b.age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//int main()
//{
//	person a("tom", 20);
//	person b("mike", 30);
//	bool ret = compare(a, b);
//	if (ret) {
//		cout << "a==b" << endl;
//	}
//	else if (!ret) {
//		cout << "a!=b" << endl;
//	}
//	return 0;
//}