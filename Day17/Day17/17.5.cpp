#include<iostream>
using namespace std;

template<class T1>
class CList {
	T1 arr[100];
	int len;
public:
	CList(int l) : len(l){
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		for (int i = len; i < 100; i++) {
			arr[i] = -1;
		}
	}
	void insert(int seat, T1 num) {

		for (int i = len; i > seat; i--) {
			
			arr[i] = arr[i - 1];
		}
		arr[seat] = num;
		len++;
	}
	void remove(int seat) {
		for (int i = seat; i < len; i++) {
			arr[i] = arr[i + 1];
		}
		len--;
	}
	void print() {
		for (int i = 0; i < len; i++) {
			cout << arr[i] << " \n"[i == len - 1];
		}
	}
};

int main()
{
	int len;
	cin >> len;
	CList<int> obj(len);
	int seat,num;
	cin >> seat >> num;
	obj.insert(seat, num);
	cin >> seat;
	obj.remove(seat);
	obj.print();
	cin >> len;
	CList<double> obj2(len);
	double numd;
	cin >> seat >> numd;
	obj2.insert(seat, numd);
	cin >> seat;
	obj2.remove(seat);
	obj2.print();
	return 0;
}