//#include<iostream>
//using namespace std;
//
//class Complex
//{
//private:
//	double real; 
//	double imag; 
//public:
//	Complex() {
//		real = 0;
//		imag = 0;
//	};
//	Complex(double r, double i) {
//		real = r;
//		imag = i;
//	};
//	friend Complex addCom(const Complex& c1, const Complex& c2);
//	friend Complex minusCom(const Complex& c1, const Complex& c2);
//	friend void outCom(const Complex& c);
//};
//
//Complex addCom(const Complex& c1, const Complex& c2) {
//	Complex temp;
//	temp.real = c1.real + c2.real;
//	temp.imag = c1.imag + c2.imag;
//	return temp;
//};
//
//Complex minusCom(const Complex& c1, const Complex& c2) {
//	Complex temp;
//	temp.real = c1.real - c2.real;
//	temp.imag = c1.imag - c2.imag;
//	return temp;
//}
//
//void outCom(const Complex& c) {
//	cout << "(" << c.real << "," << c.imag << ")" << endl;
//}
//
//int main()
//{
//	int r0, i0;
//	cin >> r0 >> i0;
//	Complex c0(r0, i0);
//	int t;
//	cin >> t;
//	char op;
//	int r, i;
//	while (t--) {
//		cin >> op >> r >> i;
//		Complex c1(r, i);
//		if (op == '+') {
//			c0 = addCom(c0, c1);
//			outCom(c0);
//		}
//		else if (op == '-') {
//			c0 = minusCom(c0, c1);
//			outCom(c0);
//		}
//	}
//	return 0;
//}