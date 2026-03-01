//#include<iostream>
//using namespace std;
//
//class CN;
//class EN;
//
//class weight {
//protected:
//	string kind;
//	int gram;
//public:
//	weight(string k,int g) :kind(k),gram(g) {};
//	virtual void print() = 0;
//};
//
//class CN : public weight {
//protected:
//	int jin;
//	int liang;
//	int qian;
//public:
//	CN(int j,int l,int q,string k,int g) :jin(j), liang(l), qian(q), weight(k, g) {};
//	void Convert(int g){
//		jin = g / 500;
//		g %= 500;
//		liang = g / 50;
//		g %= 50;
//		qian = g / 5;
//		g %= 5;
//		gram = g;
//	}
//	void print() {
//		cout << kind << ":" << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << endl;
//	}
//};
//
//class EN :public weight {
//protected:
//	int pound;
//	int ounce;
//	int dram;
//public:
//	EN(int p, int o, int d, string k, int g) :pound(p), ounce(o), dram(d), weight(k, g) {};
//	void Convert(int g) {
//		pound = g / 512;
//		g %= 512;
//		ounce = g / 32;
//		g %= 32;
//		dram = g / 2;
//		g %= 2;
//		gram = g;
//	}
//	operator CN() {
//		int total = pound * 512 + ounce * 32 + dram * 2 + gram;
//		int j = total / 500;
//		total %= 500;
//		int l = total / 50;
//		total %= 50;
//		int q = total / 5;
//		total %= 5;
//		return CN(j, l, q, "中国计重", total);
//	}
//	void print() {
//		cout << kind << ":" << pound << "磅" << ounce << "盎司" << dram << "打兰" << gram << "克" << endl;
//	}
//};
//
//int main()
//{
//	int g1, g2;
//	cin >> g1 >> g2;
//	CN cn(0, 0, 0, "中国计重", 0);
//	cn.Convert(g1);
//	cn.print();
//	EN en(0, 0, 0, "英国计重", 0);
//	en.Convert(g2);
//	en.print();
//	cn = en;
//	cn.print();
//	return 0;
//}