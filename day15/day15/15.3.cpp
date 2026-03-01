//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Time {
//private:
//	int hour, mintue, second;
//public:
//	Time() :hour(0), mintue(0), second(0) {};
//	Time(int h,int m,int s) :hour(h), mintue(m), second(s) {};
//	friend Time operator ++(Time& t) {
//		t.second++;
//		if (t.second == 60) {
//			t.second = 0;
//			t.mintue += 1;
//			if (t.mintue == 60) {
//				t.mintue = 0;
//				t.hour += 1;
//				if (t.hour == 12) {
//					t.hour = 0;
//				}
//			}
//		}
//		return t;
//	}
//	friend Time operator --(Time& t, int) {
//		Time temp(t);
//		t.second--;
//		if (t.second < 0) {
//			t.second = 59;
//			t.mintue -= 1;
//			if (t.mintue < 0) {
//				t.mintue = 59;
//				t.hour -= 1;
//				if (t.hour < 0) {
//					t.hour = 11;
//				}
//			}
//		}
//		return temp;
//	}
//	void show() {
//		cout << hour << ":" << mintue << ":" << second << endl;
//	}
//};
//
//int main()
//{
//	int h, m, s;
//	cin >> h >> m >> s;
//	Time T(h, m, s);
//	int t,op;
//	cin >> t;
//	while (t--) {
//		cin >> op;
//		if (op > 0) {
//			while (op--) {
//				++T;
//			}
//			T.show();
//		}
//		else if (op < 0) {
//			op = abs(op);
//			while (op--) {
//				T--;
//			}
//			T.show();
//		}
//		else if (op == 0) {
//			T.show();
//		}
//	}
//	return 0;
//}