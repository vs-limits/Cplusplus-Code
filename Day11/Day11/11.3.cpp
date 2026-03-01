//#include<iostream>
//using namespace std;
//
//class Animal {
//protected:
//	string name;
//	int age;
//public:
//	Animal(string n,int a):name(n),age(a){}
//	virtual void speak() = 0;
//};
//
//class tiger :public Animal {
//public:
//	tiger(string n,int a):Animal(n,a){}
//	void speak() {
//		cout << "Hello,I am "<< name << ",AOOO." << endl;
//	}
//};
//class duck :public Animal {
//public:
//	duck(string n, int a) :Animal(n, a) {}
//	void speak() {
//		cout << "Hello,I am "<< name <<",GAGA." << endl;
//	}
//};
//class dog :public Animal {
//public:
//	dog(string n, int a) :Animal(n, a) {}
//	void speak() {
//		cout << "Hello,I am " << name << ",WangWang." << endl;
//	}
//};
//class pig :public Animal {
//public:
//	pig(string n, int a) :Animal(n, a) {}
//	void speak() {
//		cout << "Hello,I am " << name << ",HENGHENG." << endl;
//	}
//};
//int main()
//{
//	int t;
//	cin >> t;
//	string type, name;
//	int age;
//	Animal* an;
//	while (t--) {
//		cin >> type >> name >> age;
//		if (type == "Tiger") {
//			an = new tiger(name, age);
//			an->speak();
//		}else if (type == "Pig") {
//			an = new pig(name, age);
//			an->speak();
//		}else if (type == "Duck") {
//			//an = new duck(name, age);
//			an->speak();
//		}else if (type == "Dog") {
//			an = new dog(name, age);
//			an->speak();
//		}else {
//			cout << "There is no "<< type <<" in our Zoo." << endl;
//		}
//	}
//	return 0;
//}