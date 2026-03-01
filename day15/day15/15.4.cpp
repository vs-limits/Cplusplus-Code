//#include<iostream>
//using namespace std;
//
//class CXGraph {
//private:
//    int n;
//public:
//    CXGraph(int num) :n(num) {};
//    friend ostream& operator <<(ostream& stream, const CXGraph& g);
//    friend CXGraph& operator++(CXGraph &g) {∫Û÷√
//        if (g.n < 21) {
//            g.n += 2;
//        }
//        return g;
//    }
//    friend CXGraph operator++(CXGraph& g, int);
//    friend CXGraph& operator--(CXGraph& g) {
//        if (g.n > 1) {
//            g.n -= 2;
//        }
//        return g;
//    }
//    friend CXGraph operator--(CXGraph& g, int);
//};
//
//CXGraph operator++(CXGraph& g, int) {«∞÷√
//    CXGraph temp = g;
//    if (g.n < 21) {
//        g.n += 2;
//    }
//    return temp;
//}
//
//CXGraph operator--(CXGraph& g, int) {
//    CXGraph temp = g;
//    if (g.n > 1) {
//        g.n -= 2;
//    }
//    return temp;
//}
//ostream& operator<< (ostream& out, const CXGraph& g) {
//    for (int i = g.n; i > 0; i -= 2) {
//        for (int j = g.n - i; j > 0; j -= 2) {
//            out << " ";
//        }
//        for (int j = 1; j <= i; j++) {
//            out << "X";
//        }
//        out << endl;
//    }
//    for (int i = 3; i <= g.n; i += 2) {
//        for (int j = g.n - i; j > 0; j -= 2) {
//            out << " ";
//        }
//        for (int j = 1; j <= i; j++) {
//            out << "X";
//        }
//        out << endl;
//    }
//    return out;
//}
//int main()
//{
//    int t, n;
//    string command;
//    cin >> n;
//    CXGraph xGraph(n);
//    cin >> t;
//    while (t--)
//    {
//        cin >> command;
//        if (command == "show++")
//        {
//            cout << xGraph++ << endl;
//        }
//        else if (command == "++show")
//        {
//            cout << ++xGraph << endl;
//        }
//        else if (command == "show--")
//        {
//            cout << xGraph-- << endl;
//        }
//        else if (command == "--show")
//        {
//            cout << --xGraph << endl;
//        }
//        else if (command == "show")
//        {
//            cout << xGraph << endl;
//        }
//    }
//    return 0;
//}