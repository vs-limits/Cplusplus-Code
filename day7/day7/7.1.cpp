//#include<iostream>
//using namespace std;
//
//class obj {
//private:
//	int value;
//public:
//	obj() {
//		cout << "Constructed by default, value = 0" << endl;
//	};
//	obj(int v) {
//		value = v;
//		cout << "Constructed using one argument constructor, value = " << value << endl;
//	}
//	obj(const obj& obj1) {
//		value = obj1.value;
//		cout << "Constructed using copy constructor, value = " << value << endl;
//	}
//};
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		int tp, num;
//		cin >> tp;
//		if (tp == 0) {
//			obj obj0;
//		}
//		else if (tp == 1) {
//			cin >> num;
//			obj obj1(num);
//		}
//		else if (tp == 2) {
//			cin >> num;
//			obj obj1(num), obj2(obj1);
//		}
//	}
//	return 0;
//}