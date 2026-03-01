#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class CBook {
private:
	string name;
	string editor;
	double price;
	string publish;
public:
	CBook() :price(0) {};
	CBook(string n, string e, double p, string pub) :name(n), editor(e), price(p), publish(pub) {};
	friend istream& operator >>(istream& in, CBook& b) {
		getline(in, b.name, ',');
		getline(in, b.editor, ',');
		in >> b.price;
		in.ignore();
		getline(in, b.publish); 
		return in;
	}
	friend ostream& operator <<(ostream& stream, CBook& b) {
		stream << b.name << endl;
		stream << b.editor << endl;
		stream << fixed << setprecision(2) << b.price << endl;
		stream << b.publish;
		return stream;
	}
	friend void find(CBook* b, int n, int& max1index, int& max2index) {
		max1index = 0;
		max2index = -1;
		for (int i = 1; i < n; i++) {
			if (b[i].price > b[max1index].price) {
				max1index = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i != max1index) {
				if (max2index == -1 || b[i].price > b[max2index].price) {
					max2index = i;
				}
			}
		}
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin.ignore();
		CBook* b = new CBook[n];
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int max1 = 0, max2 = 0;
		find(b, n, max1, max2);
		cout << b[max1] << endl;
		cout << endl;
		cout << b[max2] << endl;
		delete[] b;
	}
	return 0;
}
