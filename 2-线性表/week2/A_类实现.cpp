#include<iostream>
using namespace std;
#define ok 0
#define error -1
// ˳����ඨ��
class SeqList
{
private:
   int* list;      // Ԫ������
   int maxsize;    // ˳�����󳤶�
   int size;       // ˳���ʵ�ʳ���
public:
   SeqList(int n);                          // ���캯��
   ~SeqList();                         // ��������
   int list_size();                    // ��ȡ˳���ʵ�ʳ���
   int list_insert(int i, int item);   // ����һ��Ԫ�أ������ǲ������ֵ��λ��
   int list_del(int i);                // ɾ��һ��Ԫ�أ�������ɾ����λ��
   int list_get(int i);                // ��ȡһ��Ԫ�أ������ǻ�ȡ��λ��
   void list_display();                // �������˳���
};

SeqList::SeqList(int n)
{
   maxsize = 1000;
   size = n;
   list = new int[maxsize];
   for (int i = 0; i < n; i++) {
       cin >> list[i];
   }
}
SeqList::~SeqList()
{
   delete[]list;
}
int SeqList::list_size() {
   return size;
}
int SeqList::list_insert(int i, int item) {
   if (i<=0 || i>size+1 || size == maxsize) return error;
   for (int j = size - 1; j >= i - 1; j--) 
       list[j + 1] = list[j];
   list[i - 1] = item; 
   size++;         
   return ok;
}
int SeqList::list_del(int i) {
   if (i <= 0 || i > size || size == maxsize) return error;
   for (int j = i - 1; j < size - 1; j++) {
       list[j] = list[j + 1];
   }
   size--;
   return ok;
}
int SeqList::list_get(int i) {
   if (i <= 0 || i > size || size == maxsize) return error;
   return list[i - 1];
}
void SeqList::list_display() {
   cout << size << " ";
   for (int i = 0; i < size; i++) {
       cout << list[i] << " ";
   }
   cout << endl;
}
int main() {
   int n;
   cin >> n;
   SeqList seq(n);
	seq.list_display();
   int insert, i_num;
	cin >> insert >> i_num;
   if(seq.list_insert(insert, i_num) == -1) cout << "error" << endl;
   else {
       seq.list_display();
   }
   cin >> insert >> i_num;
   if (seq.list_insert(insert, i_num) == -1) cout << "error" << endl;
   else {
       seq.list_display();
   }
   int del;
   cin >> del;
   if (seq.list_del(del) == -1) {
		cout << "error" << endl;
   }
   else {
		seq.list_display();
   }
   cin >> del;
   if (seq.list_del(del) == -1) {
       cout << "error" << endl;
   }
   else {
       seq.list_display();
   }
   int get;
   cin >> get;
   if(seq.list_get(get) == -1) cout << "error" << endl;
   else {
       cout << seq.list_get(get) << endl;
   }
   cin >> get;
   if (seq.list_get(get) == -1) cout << "error" << endl;
   else {
       cout << seq.list_get(get) << endl;
   }
	return 0;
}