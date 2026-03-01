//#include<iostream>
//using namespace std;
//
//class Member {
//protected:
//	int No;
//	string name;
//	int point;
//public:
//	Member() :No(0), name(""), point(0) {};
//	Member(int no, string n, int p) :No(no), name(n), point(p) {};
//	void add(int bill) {
//		point += bill;
//	}
//	int exchange(int t_p) {
//		point -= (t_p / 100) * 100;
//		return t_p / 100;
//	}
//	void Mprint() {
//		cout << "普通会员" << No << "--" << name << "--" << point << endl;
//	}
//};
//
//class VIP:public Member{
//protected:
//	int addrate;
//	int exchangerate;
//public:
//	VIP() :addrate(0),exchangerate(0),Member(){};
//	VIP(int ar,int er,int no, string n, int p) :addrate(ar), exchangerate(er), Member(no,n,p) {};
//	void add(int bill) {
//		point += addrate * bill;
//	}
//	int exchange(int t_p) {
//		point -= (t_p / exchangerate) * exchangerate;
//		return t_p / exchangerate;
//	}
//	void Vprint() {
//		cout << "贵宾会员" << No << "--" << name << "--" << point << endl;
//	}
//};
//
//int main()
//{
//	int no, point,bill,t_p;
//	string name;
//	cin >> no >> name >> point >> bill >> t_p;
//	Member m1(no, name, point);
//	m1.add(bill);
//	m1.exchange(t_p);
//	m1.Mprint();
//	int ar, er;
//	cin >> no >> name >> point >> ar >> er;
//	VIP m2(ar, er, no, name, point);
//	cin >> bill >> t_p;
//	m2.add(bill);
//	m2.exchange(t_p);
//	m2.Vprint();
//	return 0;
//}