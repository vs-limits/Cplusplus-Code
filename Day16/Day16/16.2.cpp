//#include<iostream>
//using namespace std;
//
//class Node2D {
//private:
//	string location;
//public:
//	Node2D() { location = ""; }
//	Node2D(string l) { location = l; }
//	string get_loca() {
//		return location;
//	}
//};
//
//class Body : virtual public Node2D {
//private:
//	int maxHealth, health, defense;
//public:
//	Body() :maxHealth(0), health(0), defense(0) {};
//	Body(int mH,int de) :maxHealth(mH), defense(de) ,health(mH){};
//	int get_de() {
//		return defense;
//	}
//	void set_h(int a) {
//		health -= a;
//	}
//	int get_h() {
//		return health;
//	}
//};
//
//class Weapon : virtual public Node2D {
//private:
//	string w_name;
//	int damage;
//public:
//	Weapon() :w_name(""), damage(0) {};
//	Weapon(string w_n,int da) :w_name(w_n), damage(da) {};
//	int get_da() {
//		return damage;
//	}
//	string get_wn() {
//		return w_name;
//	}
//};
//
//class Player:public Body,public Weapon{
//private:
//	string name;
//public:
//	Player() :name(""){};
//	Player(string l, string w_n, int da, int mH, int de, string n) :Node2D(l), Weapon(w_n, da), Body(mH, de), name(n){};
//	void fight(Player& p2) {
//		cout << name << " deal " << get_da() - p2.get_de() << " damage to "<< p2.name << endl;
//		p2.set_h(get_da() - p2.get_de());
//		if (p2.get_h() > 0) {
//			cout << p2.name << " still have " << p2.get_h() << " health" << endl;
//			cout << endl;
//		}
//		else if (p2.get_h() <= 0) {
//			cout << name << " defeated " << p2.name << " by " << get_wn() << " in " << get_loca() << endl;
//		}
//	}
//	bool alive() {
//		if (get_h() > 0) { return true; }
//		else return false;
//	}
//};
//
//int main()
//{
//	string location;
//	string n1, n2;
//	int h1, h2;
//	int de1, de2;
//	string wn1, wn2;
//	int da1, da2;
//	cin >> location;
//	cin >> n1 >> h1 >> de1 >> wn1 >> da1;
//	Player p1(location, wn1, da1, h1, de1, n1);
//	cin >> n2 >> h2 >> de2 >> wn2 >> da2;
//	Player p2(location, wn2, da2, h2, de2, n2);
//	while (p1.alive() == true && p2.alive() == true) {
//		p1.fight(p2);
//		if (p1.alive() == false || p2.alive() == false) break;
//		p2.fight(p1);
//		if (p1.alive() == false || p2.alive() == false) break;
//	}
//	return 0;
//}