#include<iostream>
using namespace std;

class Group {
public:
    virtual void add(int x, int y) = 0; // 输出加法的运算结果
    virtual void sub(int x, int y) = 0; // 输出减法的运算结果
};

class GroupA :public Group {
public:
    void add(int x, int y) {
        int sum = x + y;
        cout << sum << endl;
    }
    void sub(int x, int y) {
        int diff = x - y;
        cout << diff << endl;
    }
};

class GroupB :public Group {
public:
    void add(int x, int y) {
        int sum = x + y;
        cout << sum << endl;
    }
    void sub(int x, int y) {
        int diff = 0;
        int power = 1;
        while (x > 0 || y > 0) {
            int x_t = x % 10;
            int y_t = y % 10;
            int sum = x_t - y_t;
            if (sum > 0) {
                diff += sum * power;
            }
            else if (sum < 0) {
                sum += 10;
                diff += sum * power;
            }
            power *= 10;
            x /= 10;
            y /= 10;
        }
        cout << diff << endl;
    }
};

class GroupC :public Group {
public:
    void add(int x, int y) {
        int sum = 0;
        int power = 1;
        while (x > 0 || y > 0) {
            int x_t = x % 10;
            int y_t = y % 10;
            int sum_t = x_t + y_t;
            if (sum_t >= 10) {
                sum_t -= 10;
                sum += sum_t * power;
            }
            else {
                sum += sum_t * power;
            }
            power *= 10;
            x /= 10;
            y /= 10;
        }
        cout << sum << endl;
    }
    void sub(int x, int y) {
        int diff = 0;
        int power = 1;
        while (x > 0 || y > 0) {
            int x_t = x % 10;
            int y_t = y % 10;
            int sum = x_t - y_t;
            if (sum > 0) {
                diff += sum * power;
            }
            else if (sum < 0) {
                sum += 10;
                diff += sum * power;
            }
            power *= 10;
            x /= 10;
            y /= 10;
        }
        cout << diff << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    int type, x, y;
    char op;
    Group* g;
    while (t--) {
        cin >> type >> x >> op >> y;
        if (type == 1) {
            g = new GroupA();
            if (op == '+') {
                g->add(x, y);
            }
            else if (op == '-') {
                g->sub(x, y);
            }
        }
        else if (type == 2) {
            g = new GroupB();
            if (op == '+') {
                g->add(x, y);
            }
            else if (op == '-') {
                g->sub(x, y);
            }
        }
        else if (type == 3) {
            g = new GroupC();
            if (op == '+') {
                g->add(x, y);
            }
            else if (op == '-') {
                g->sub(x, y);
            }
        }
    }
    return 0;
}