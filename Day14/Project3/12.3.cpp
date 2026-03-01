//#include<iostream>
//using namespace std;
//
//class Vector
//{
//private:
//    int vec[5];
//public:
//    Vector(int v[]) {
//        for (int i = 0; i < 5; i++) {
//            vec[i] = v[i];
//        }
//    };
//    Vector() {
//        for (int i = 0; i < 5; i++) {
//            vec[i] = 0;
//        }
//    };
//    Vector operator +(const Vector& obj) {
//        Vector v_t;
//        for (int i = 0; i < 5; i++) {
//            v_t.vec[i] = this->vec[i] + obj.vec[i];
//        }
//        return v_t;
//    };
//    Vector operator -(const Vector& obj) {
//        Vector v_t;
//        for (int i = 0; i < 5; i++) {
//            v_t.vec[i] = this->vec[i] - obj.vec[i];
//        }
//        return v_t;
//    };
//    void print() {
//        for (int i = 0; i < 5; i++) {
//            cout << vec[i];
//            cout << " ";
//        }
//        cout << endl;
//    };
//};
//
//int main()
//{
//    int x[5], y[5];
//    int x_t, y_t;
//    for (int i = 0; i < 5; i++) {
//        cin >> x_t;
//        x[i] = x_t;
//    }
//    for (int i = 0; i < 5; i++) {
//        cin >> y_t;
//        y[i] = y_t;
//    }
//    Vector v1(x);
//    Vector v2(y);
//    Vector v3;
//    v3 = v1 + v2;
//    v3.print();
//    v3 = v1 - v2;
//    v3.print();
//	return 0;
//}