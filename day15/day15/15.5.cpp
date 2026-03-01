#include<iostream>
using namespace std;

class Cpoint {
private:
	int x, y;
public:
	Cpoint(int X, int Y) :x(X), y(Y) {};
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

class CRectangle {
private:
	Cpoint leftpoint;
	Cpoint rightpoint;
public:
	CRectangle(int x1, int y1, int x2, int y2) :leftpoint(x1, y1), rightpoint(x2, y2) {};
    bool operator >(Cpoint p) {
        int x = p.getX();
        int y = p.getY();
        int leftX = leftpoint.getX();
        int rightX = rightpoint.getX();
        int topY = leftpoint.getY();
        int bottomY = rightpoint.getY();
        // 检查点的x坐标在矩形x范围内，y坐标在矩形y范围内
        return (x >= leftX && x <= rightX && y >= bottomY && y <= topY);
    }
    bool operator >(CRectangle& rect) {
        if (*this > rect.leftpoint && *this > rect.rightpoint) {
            return true;
        }
        return false;
    }
    bool operator ==(CRectangle& p) {
        if (this->leftpoint.getX() == p.leftpoint.getX() &&
            this->leftpoint.getY() == p.leftpoint.getY() &&
            this->rightpoint.getX() == p.rightpoint.getX() &&
            this->rightpoint.getY() == p.rightpoint.getY()) {
            return true;
        }
        return false;
    }
    bool operator *(CRectangle& p) {
        if (p.leftpoint.getX() > this->rightpoint.getX() ||
            p.rightpoint.getY() > this->leftpoint.getY() ||
            p.rightpoint.getX() < this->leftpoint.getX() ||
            p.leftpoint.getY() < this->rightpoint.getY()) {
            return false;
        }
        return true;
    }
    friend ostream& operator <<(ostream &stream,CRectangle &p) {
        stream << p.leftpoint.getX() << " " << p.leftpoint.getY() << " " << p.rightpoint.getX() << " " << p.rightpoint.getY();
        return stream;
    }
    operator int() {
        int width = leftpoint.getY() - rightpoint.getY();
        int longth = rightpoint.getX() - leftpoint.getX();
        return width * longth;
    }
};


int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}