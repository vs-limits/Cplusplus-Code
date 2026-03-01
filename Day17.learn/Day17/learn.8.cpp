#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class person;

template<class T1, class T2>
void show(person<T1, T2>& p) {
	cout << "name:" << p.name << " " << "age:" << p.age << endl;
}

template<class T1,class T2>
class person {
private:
	T1 name;
	T2 age;
public:
	person(T1 n, T2 a) {
		name = n;
		age = a;
	};
	friend void show<>(person<T1, T2>& p);
};

int main()
{
	person<string, int> p("Joker", 29);
	show(p);
	return 0;
}