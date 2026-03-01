//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//class CDate {
//protected:
//	int year, month, day;
//public:
//	CDate() :year(0), month(0), day(0) {};
//	CDate(int y, int m, int d) :year(y), month(m), day(d) {};
//	bool isLeapYear() {
//		return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//	}
//	int compare(CDate& begin) {
//		int cnt = 0; 
//		if (year == begin.year && month == begin.month && day == begin.day) return 0; 
//		else if (year < begin.year || year == begin.year && (month < begin.month || (month == begin.month && day < begin.day))) {
//			return -1;
//		}
//		else {
//			for (int i = begin.year; i <= year; i++) {
//				if (i == begin.year && isLeapYear())days[2] = 29; 
//				else days[2] = 28;
//				for (int j = 1; j <= 12; j++) {
//					for (int k = 1; k <= days[j]; k++) {
//						if (i == begin.year && (j == begin.month && k <= begin.day || j < begin.month)) continue;
//							cnt++; 
//							if (i == year && j == month && k == day) return cnt;
//					}
//				}
//			}
//		}
//	}
//};
//
//class pet {
//protected:
//	string name;
//	float length;
//	float weight;
//	CDate current;
//public:
//	pet() :name(""), length(0), weight(0) {};
//	pet(string n,float len,float wei,int y,int m,int d) :name(n), length(len), weight(wei),current(y,m,d) {};
//	virtual void display(CDate& begin) = 0;
//};
//
//class cat :public pet {
//public:
//	cat(string n, float len, float wei, int y, int m, int d) :pet(n, len, wei, y, m, d) {};
//	void display(CDate& begin) {
//		int totalday = current.compare(begin);
//		length = length + 0.1 * totalday;
//		weight = weight + 0.2 * totalday;
//		cout << name << " after " << current.compare(begin) << " day: length=" << fixed << setprecision(2) << length << ",weight=" << fixed << setprecision(2) << weight << endl;
//	}
//};
//
//class dog :public pet {
//public:
//	dog(string n, float len, float wei, int y, int m, int d) :pet(n, len, wei, y, m, d) {};
//	void display(CDate& begin) {
//		int totalday = current.compare(begin);
//		length = length + 0.2 * totalday;
//		weight = weight + 0.1 * totalday;
//		cout << name << " after " << current.compare(begin) << " day: length=" << fixed << setprecision(2) << length << ",weight=" << fixed << setprecision(2)<< weight << endl;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int y0, m0, d0;
//	cin >> y0 >> m0 >> d0;
//	CDate begin(y0, m0, d0);
//	pet* pt;
//	while (t--) {
//		int type;
//		string name;
//		int length, weight;
//		int y, m, d;
//		cin >> type >> name >> length >> weight >> y >> m >> d;
//		CDate current(y, m, d);
//		if (current.compare(begin) == -1) {
//			cout << "error" << endl;
//		}
//		else {
//			if (type == 1) {
//				pt = new cat(name, length, weight, y, m, d);
//				pt->display(begin);
//			}
//			else if (type == 2) {
//				pt = new dog(name, length, weight, y, m, d);
//				pt->display(begin);
//			}
//		}
//	}
//	return 0;
//}