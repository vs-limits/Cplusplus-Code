#include<iostream>
using namespace std;
class SeqList {
private:
	int* array;
	int size;
	int maxsize;
public:
	SeqList(int n,int m) {
		size = n + m;
		maxsize = 1000;
		array = new int[maxsize];
	}
	void insert(int n, int m, int a1[], int a2[]) {
		int i = 0, j = 0,k=0;
		while (i < n && j < m) {
			if (a1[i] < a2[j]) {
				array[k++] = a1[i];
				i++;
			}
			else {
				array[k++] = a2[j];
				j++;
			}
		}
		
		while (i < n) {
			array[k++] = a1[i];
			i++;
		}
		while (j < m) {
			array[k++] = a2[j];
			j++;
		}
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
	int n, m;
	cin >> n;
	int* a1 = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a1[i];
	}
	cin >> m;
	int* a2 = new int[m];
	for(int j = 0; j < m; j++) {
		cin >> a2[j];
	}
	SeqList seq(n, m);
	seq.insert(n, m, a1, a2);
	seq.print();
}