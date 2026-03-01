#include<iostream>
using namespace std;

class electrical {
protected:
	int No;
	int power;
public:
	electrical() :No(0), power(0) {};
	electrical(int no,int p) :No(no), power(p) {};
	void print() {}
};

class fan :virtual public electrical {
protected:
	int situation;
	int windpower;
public:
	fan() :situation(0),windpower(0) ,electrical(){};
	fan(int s,int wp,int no,int p) :situation(s), windpower(wp), electrical(no,p) {};
	void Scontrol(int con) {
		situation = con;
	}
	void WPcontrol(int n) {
		windpower = n;
	}
};

class wet :virtual public electrical {
protected:
	double Cvolumn;
	double Mvolumn;
public:
	wet() :Cvolumn(0), Mvolumn(0), electrical() {};
	wet(double C, double M, int no, int p) :Cvolumn(C), Mvolumn(M), electrical(no, p) {};
	int warning() {
		if (Cvolumn >= Mvolumn * 0.5) return 1;
		else if (Cvolumn >= Mvolumn * 0.1 && Cvolumn < Mvolumn * 0.5) return 2;
		else if (Cvolumn < Mvolumn * 0.1) return 3;
	}
};

class wetfan :public fan, public wet {
protected:
	int level;
public:
	wetfan() :level(0),fan(),wet(),electrical() {};
	wetfan(int l,int s,int wp,double C, double M, int no, int p) :level(0),fan(s,wp,0,0),wet(C,M,0,0),electrical(no, p) {};
	void control(int n) {
		if (n == 0) {
			level = 0;
		}
		else if (n == 1) {
			level = 1;
			Scontrol(0);
			WPcontrol(1);
		}
		else if (n == 2) {
			level = 2;
			Scontrol(1);
			WPcontrol(2);
		}
		else if (n == 3) {
			level = 3;
			Scontrol(1);
			WPcontrol(3);
		}
	}
	void print() {
		cout << "加湿风扇--档位" << level << endl;
		cout << "编号" << No << "--功率" << power << "W" << endl;
		if (situation == 0) {
			cout << "定向吹风--风力" << windpower << "级" << endl;
		}
		else if (situation == 1) {
			cout << "旋转吹风--风力" << windpower << "级" << endl;
		}
		cout << "实际水容量" << Cvolumn << "升--";
		if (warning() == 1) {
			cout << "水量正常" << endl;
		}
		else if (warning() == 2) {
			cout << "水量偏低" << endl;
		}
		else if (warning() == 3) {
			cout << "水量不足" << endl;
		}
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int no, power, s, wp, C, M, level,n;
		cin >> no >> power >> s >> wp >> C >> M >> level >> n;
		wetfan m1(level, s, wp, C, M, no, power);
		m1.control(n);
		m1.print();
	}
	return 0;
}