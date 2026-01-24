#include<iostream>
#include<cmath>
using namespace std;
class SeqList {
private:
	int* array;
	int size;
	int maxsize;
public:
	SeqList(int n) {
		size = n;
		maxsize = 1000;
		array = new int[maxsize];
		for (int i = 0; i < size; i++) {
			cin >> array[i];
		}
	}
	void rightMove(int k) {
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = array[(i - k + size) % size];
		}
		for (int i = 0; i < size; i++) {
			array[i] = temp[i];
		}
	}
	void leftMove(int k) {
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = array[(i + k) % size];
		}
		for (int i = 0; i < size; i++) {
			array[i] = temp[i];
		}
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int n;
	cin >> n;
	SeqList seq(n);
	seq.print();
	int op, k;
	cin >> op >> k;
	if (op == 0) {
		seq.leftMove(k);
		seq.print();
	}
	else {
		seq.rightMove(k);
		seq.print();
	}
	cin >> op >> k;
	if (op == 0) {
		seq.leftMove(k);
		seq.print();
	}
	else {
		seq.rightMove(k);
		seq.print();
	}
}