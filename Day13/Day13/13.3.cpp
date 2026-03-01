//#include<iostream>
//using namespace std;
//
//class animal {
//protected:
//	string name;
//	string type;
//	int age;
//public:
//	animal(string n, string t, int a) :name(n), type(t), age(a) {};
//	virtual void speak() = 0;
//};
//
//class tiger : public animal {
//public:
//	tiger(string n, string t, int a) : animal(n, t, a) {};
//	void speak() {
//		cout << "Hello,I am " << name << ",AOOO." << endl;
//	}
//};
//
//class pig : public animal {
//public:
//	pig(string n, string t, int a) : animal(n, t, a) {};
//	void speak() {
//		cout << "Hello,I am " << name << ",HENGHENG." << endl;
//	}
//};
//
//class duck : public animal {
//public:
//	duck(string n, string t, int a) : animal(n, t, a) {};
//	void speak() {
//		cout << "Hello,I am " << name << ",GAGA." << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	animal* obj;
//	while (t--) {
//		string n, t;
//		int a;
//		cin >> t >> n >> a;
//		if (t == "Tiger") {
//			animal* obj = new tiger(n, t, a);
//			obj->speak();
//		}
//		else if (t == "Pig") {
//			animal* obj = new pig(n, t, a);
//			obj->speak();
//		}
//		else if (t == "Duck") {
//			animal* obj = new duck(n, t, a);
//			obj->speak();
//		}
//		else {
//			cout << "There is no " << t << " in our Zoo." << endl;
//		}
//	}
//	return 0;
//}