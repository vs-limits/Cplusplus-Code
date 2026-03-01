//#include<iostream>
//using namespace std;
//
//class Fraction {
//private:
//	int fz, fm;
//public:
//	Fraction() {};
//	Fraction(int z, int m) {
//		fz = z;
//		fm = m;
//	}
//	Fraction operator+(const Fraction& f2) {
//		Fraction f_t;
//		f_t.fz = this->fz * f2.fm + this->fm * f2.fz;
//		f_t.fm = this->fm * f2.fm;
//		return f_t;
//	}
//	Fraction operator-(const Fraction& f2) {
//		Fraction f_t;
//		f_t.fz = this->fz * f2.fm - this->fm * f2.fz;
//		f_t.fm = this->fm * f2.fm;
//		return f_t;
//	}
//	Fraction operator*(const Fraction& f2) {
//		Fraction f_t;
//		f_t.fz = this->fz * f2.fz;
//		f_t.fm = this->fm * f2.fm;
//		return f_t;
//	}
//	Fraction operator/(const Fraction& f2) {
//		Fraction f_t;
//		f_t.fz = this->fz * f2.fm;
//		f_t.fm = this->fm * f2.fz;
//		return f_t;
//	}
//	void show() {
//		cout << "fraction=" << fz << "/" << fm << endl;
//	}
//};
//
//int main()
//{
//	int fz1, fm1, fz2, fm2;
//	cin >> fz1 >> fm1 >> fz2 >> fm2;
//	Fraction f1(fz1, fm1), f2(fz2, fm2);
//	Fraction f3;
//	f3 = f1 + f2;
//	f3.show();
//	f3 = f1 - f2;
//	f3.show();
//	f3 = f1 * f2;
//	f3.show();
//	f3 = f1 / f2;
//	f3.show();
//	return 0;
//}