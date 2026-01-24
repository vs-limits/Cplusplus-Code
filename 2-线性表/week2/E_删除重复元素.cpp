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
       for (int i = 0; i < n; i++) {
           cin >> array[i];
       }
   }
   ~SeqList() {
       delete[] array;
   }
   void delsame() {
    //遇到不同的才更新数组
       if (size == 0) return;
       int k = 0;
       for (int i = 1; i < size; i++) {
           if (array[i] != array[k]) {
               k++;
               array[k] = array[i];
           }
       }
       size = k + 1;
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
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       SeqList seq(n);
       seq.delsame();
       seq.print();
   }
   return 0;
}