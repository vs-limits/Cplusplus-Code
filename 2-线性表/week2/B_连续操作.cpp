#include<iostream>
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
	void multiinsert(int i, int n, int item[]) {
			for (int j = size - 1; j >= i-1; j--) {
				array[j + n] = array[j];
		}
			for (int j = 0; j < n; j++) {
				array[i-1 + j] = item[j];
			}
			size+=n;
	}
	void multidel(int i, int n) {
		for (int j = i - 1; j < size; j++) {
			array[j] = array[j + n];
		}
		size-=n;
	}
	void print() {
		cout << size << " ";
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
	int insert, num;
	cin >> insert >> num;
	int* item = new int[num];
	for(int i = 0;i < num;i++) {
		cin >> item[i];
	}
	
	seq.multiinsert(insert, num, item);
	seq.print();
	delete[] item;
	int del, delnum;
	cin >> del >> delnum;
	seq.multidel(del, delnum);
	seq.print();
	return 0;
}