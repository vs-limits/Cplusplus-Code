//#include<iostream>
//using namespace std;
//
//class card {
//protected:
//	int ID;
//	char Cname;
//	int Counter;
//public:
//	card() :ID(0), Cname(0), Counter(0) {};
//	void initial(int id, char n, int count){
//		ID = id;
//		Cname = n;
//		Counter = count;
//	};
//	int save(int s) {
//		if (s <= 0) return -1;
//		else if (s > 0) {
//			Counter += s;
//			return 1;
//		}
//	}
//	int take(int t) {
//		if (t <= 0 || t > Counter) return -1;
//		else if (t > 0 && t <= Counter) {
//			Counter -= t;
//			return 1;
//		}
//	}
//	void info() {
//		cout << ID << "-" << Cname << "-" << Counter << endl;
//	}
//};
//
//class Tcard: public card {
//protected:
//	int Tcounter;
//public:
//	Tcard() :Tcounter(0), card() {};
//	void initial(int id, char n, int count,int Tc) {
//		ID = id;
//		Cname = n;
//		Counter = count;
//		Tcounter = Tc;
//	};
//	int transfer(int tr) {
//		if (tr <= 0 || tr > Counter) return -1;
//		else if (tr > 0 && tr <= Counter) {
//			Counter -= tr;
//			Tcounter += tr;
//			return 1;
//		}
//	}
//	void info() {
//		cout << ID << "-" << Cname << "-" << Counter << "-" << Tcounter << endl;
//	}
//};
//
//class Vcard : public card{
//protected:
//	int Credit;
//public:
//	Vcard() :Credit(0), card() {};
//	void initial(int id, char n, int count,int cr) {
//		ID = id;
//		Cname = n;
//		Counter = count;
//		Credit = cr;
//	};
//	int over(int o) {
//		if (o <= 0 || o > Credit + Counter) return -1;
//		else if (o > 0 && o < Credit + Counter) {
//			Credit -= (o - Counter);
//			Counter = 0;
//			return 1;
//		}
//	}
//	void info() {
//		cout << ID << "-" << Cname << "-" << Counter << "-" << Credit << endl;
//	}
//};
//
//int main() {
//	int id1, id2, id3;
//	int c1, c2, c3;
//	char tp1, tp2, tp3;
//	int Tc, Cr;
//	cin >> id1 >> tp1 >> c1;
//	card m1;
//	m1.initial(id1, tp1, c1);
//	cin >> id2 >> tp2 >> c2 >> Tc;
//	Tcard m2;
//	m2.initial(id2, tp2, c2, Tc);
//	cin >> id3 >> tp3 >> c3 >> Cr;
//	Vcard m3;
//	m3.initial(id3, tp3, c3, Cr);
//	int op1, op2, op3, op4;
//	cin >> op1 >> op2 >> op3 >> op4;
//	m1.save(op1);
//	m1.save(op2);
//	m1.take(op3);
//	m1.take(op4);
//	m1.info();
//	cin >> op1 >> op2 >> op3 >> op4;
//	m2.save(op1);
//	m2.take(op2);
//	m2.transfer(op3);
//	m2.transfer(op4);
//	m2.info();
//	cin >> op1 >> op2 >> op3 >> op4;
//	m3.save(op1);
//	m3.take(op2);
//	m3.over(op3);
//	m3.over(op4);
//	m3.info();
//}