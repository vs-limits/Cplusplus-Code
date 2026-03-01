//#include<iostream>
//using namespace std;
//
//class Complex
//{
//private:
//    float real, image;
//public:
//    Complex() {
//        real = 0;
//        image = 0;
//    };
//    Complex(float x, float y) {
//        real = x;
//        image = y;
//    }
//    friend Complex operator+(Complex& c1, Complex& c2) {
//        Complex c_t;
//        c_t.real = c1.real + c2.real;
//        c_t.image = c1.image + c2.image;
//        return c_t;
//    };
//    friend Complex operator-(Complex& c1, Complex& c2) {
//        Complex c_t;
//        c_t.real = c1.real - c2.real;
//        c_t.image = c1.image - c2.image;
//        return c_t;
//    };
//    friend Complex operator*(Complex& c1, Complex& c2) {
//        Complex c_t;
//        c_t.real = c1.real * c2.real - c1.image * c2.image;
//        c_t.image = c1.real * c2.image + c1.image * c2.real;
//        return c_t;
//    };
//    void show() {
//        cout << "Real=" << real << " Image=" << image << endl;
//    };
//};
//
//int main()
//{
//    float r1, i1, r2, i2;
//    cin >> r1 >> i1 >> r2 >> i2;
//    Complex c1(r1, i1), c2(r2, i2);
//    Complex c3, c4, c5;
//    c3 = c1 + c2;
//    c3.show();
//    c4 = c1 - c2;
//    c4.show();
//    c5 = c1 * c2;
//    c5.show();
//	return 0;
//}