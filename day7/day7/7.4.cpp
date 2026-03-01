#include<iostream>
using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate() {
        year = 0;
        month = 0;
        day = 0;
    }
    CDate(int y, int m, int d);
    bool isLeapYear();
    int getYear();
    int getMonth();
    int getDay();
    int getDayofYear();
};

CDate::CDate(int y, int m, int d)
{
    year = y, month = m, day = d;
}

bool CDate::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int CDate::getYear()
{
    return year;
}

int CDate::getMonth()
{
    return month;
}

int CDate::getDay()
{
    return day;
}

int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear())
    {
        a[2]++;
    }
    // 求日期的天数
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}

class App {
private:
    string name;
    string type,media;
    CDate date;
public:
    App(string n, char t, char m, CDate d) {
        name = n;
        if (t == 'O') {
            type = "original";
        }
        else if (t == 'T') {
            type = "trial";
        }
        else if (t == 'B') {
            type = "backup";
        }
        if (m == 'D') {
            media = "optical disk";
        }
        else if (m == 'U') {
            media = "USB disk";
        }
        else if (m == 'H') {
            media = "hard disk";
        }
        date = d;
    }
    App(const App& a1) {
        name = a1.name;
        type = "backup";
        media = "hard disk";
        date = a1.date;
    }
    int isEffective() {
        if (date.getYear() < 2015) {
            return 0;
        }
        else if (date.getYear() >= 2015) {
            return 1;
        }
    }
    int time() {
        if (date.getYear() == 2015) {
            if (date.getDayofYear() < CDate(2015, 4, 7).getDayofYear()) {
                return 0;
            }
            else {
                return date.getDayofYear() - CDate(2015, 4, 7).getDayofYear();
            }
        }
        else if (date.getYear() > 2015) {
            int sum = 268;
            for (int i = 2016; i < date.getYear(); i++) {
                if (CDate(i, 1, 1).isLeapYear()) {
                    sum += 366;
                }
                else {
                    sum += 365;
                }
            }
            sum += date.getDayofYear();
            return sum;
        }
    }
    void display() {
        cout << "name:" << name << endl;
        cout << "type:" << type << endl;
        cout << "media:" << media << endl;
        if (date.getYear() == 0) {
            cout << "this software has unlimited use" << endl;
        }
        else if (date.getYear() != 0) {
            if (isEffective() == 0) {
                cout << "this software has expired" << endl;
            }
            else if (isEffective() == 1) {
                if (time() == 0) {
                    cout << "this software has expired" << endl;
                }
                else if(time() != 0) {
                    cout << "this software is going to be expired in " << time() << " days" << endl;;
                }
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    string n;
    char tp, ma;
    int y, m, d;
    while (t--) {
        cin >> n >> tp >> ma >> y >> m >> d;
        CDate date(y, m, d);
        App a(n, tp, ma, date);
        a.display();
        cout << endl;
        App a1(a);
        a1.display();
        cout << endl;
    }
	return 0;
}