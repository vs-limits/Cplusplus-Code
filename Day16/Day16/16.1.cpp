//#include<iostream>
//using namespace std;
//
//class video {
//private:
//	string name;
//	int rent;
//	string statu;
//	string type;
//public:
//	video() :name(""), rent(0), statu(""), type("") {};
//	video(int t,string n,int r,int s){
//		name = n;
//		rent = r;
//		if (t == 1) {
//			type = "黑胶片";
//		}
//		else if (t == 2) {
//			type = "CD";
//		}
//		else if (t == 3) {
//			type = "VCD";
//		}
//		else if (t == 4) {
//			type = "DVD";
//		}
//		if (s == 0) {
//			statu = "未出租";
//		}
//		else if (s == 1) {
//			statu = "已出租";
//		}
//	};
//	void print() {
//		cout << type << "[" << name << "]" << statu << endl;
//	}
//	int fee(int d) {
//		int sum = 0;
//		sum = rent * d;
//		return sum;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int tp, r, s;
//	string n;
//	while (t--) {
//		cin >> tp >> n >> r >> s;
//		video v1(tp, n, r, s);
//		v1.print();
//		int day;
//		cin >> day;
//		if (day != 0 && s == 1) {
//			cout << "当前租金为" << v1.fee(day) << endl;
//		}
//		else if (day != 0 && s == 0) {
//			cout << "未产生租金" << endl;
//		}
//	}
//	return 0;
//}