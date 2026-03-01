//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//class Time;
//class Date {
//private:
//	int year;
//	int month;
//	int day;
//public:
//	Date() { year = 0; month = 0; day = 0; }
//	Date(int y, int m, int d) :year(y), month(m), day(d) {};
//	friend void display(Date &d1, Time &t1);
//
//};
//
//class Time {
//private:
//	int hour;
//	int mintue;
//	int second;
//public:
//	Time() :hour(0),mintue(0),second(0){};
//	Time(int h, int m, int s) :hour(h), mintue(m), second(s) {};
//	friend void display(Date &d1, Time &t1);
//};
//
//void display(Date &d1,Time &t1) {
//	cout << setfill('0') << setw(2) << d1.year << "-" << setfill('0') << setw(2) << d1.month << "-" << setfill('0') << setw(2) << d1.day << " ";
//	cout << setfill('0') << setw(2) << t1.hour << ":" << setfill('0') << setw(2) << t1.mintue << ":" << setfill('0') << setw(2) << t1.second << endl;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	int y, mo, d, h, mi, s;
//	while (t--) {
//		cin >> y >> mo >> d >> h >> mi >> s;
//		Date d1(y, mo, d);
//		Time t1(h, mi, s);
//		display(d1, t1);
//	}
//	return 0;
//}