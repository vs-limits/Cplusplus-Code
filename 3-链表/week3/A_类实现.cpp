#include<iostream>
using namespace std;
#define ok 0
#define error -1

// ������㶨��
class ListNode
{
public:
   int data;
   ListNode* next;
   ListNode() { next = NULL; }
};
// ��ͷ���ĵ������ඨ��
class LinkList
{
public:
   ListNode* head;
   int len;
   // ��������
   LinkList();
   ~LinkList();
   ListNode* LL_index(int i);      // ���ص�i������ָ�룬��������ڷ���NULL
   int LL_get(int i);              // ��ȡ��i��Ԫ�ص�����
   int LL_insert(int i, int item); // ����ֵitem�����i��λ��
   int LL_del(int i);              // ɾ����i�����
   void LL_display();              // ���������������
};
LinkList::LinkList()
{
   head = new ListNode();
   len = 0;
}
LinkList::~LinkList()
{
   ListNode* p, * q;
   p = head;
   while (p != NULL)
   {
       q = p;
       p = p->next;
       delete q;
   }
   len = 0;
   head = NULL;
}
ListNode* LinkList::LL_index(int i)
{
   if (i < 0 || i > len) return NULL;
   ListNode* p = head;
   int j = 0;
   while (p != NULL && j < i)
   {
       p = p->next;
       j++;
   }
   return p;
}
int LinkList::LL_get(int i) {
   if (i < 1 || i >len) {
       cout << "error" << endl;
       return error;
   }
   ListNode* p = LL_index(i);
   cout << p->data << endl;
   return p->data;
}
int LinkList::LL_insert(int i, int item) {
   if (i < 1 || i >len + 1) { 
       cout << "error" << endl;
       return error; 
   }
   ListNode* p, * s;
   p = LL_index(i - 1);
   s = new ListNode();
   s->next = p->next;
   p->next = s;
   s->data = item;
   len++;
   return ok;
}
int LinkList::LL_del(int i) {
   if (i < 1 || i > len) {
       cout << "error" << endl;
       return error;
   }
   ListNode* p, * q;
   p = LL_index(i - 1);
   q = LL_index(i);
   p->next = q->next;
   delete q;
   len--;
   return ok;
}
void LinkList::LL_display()
{
   ListNode* p;
   p = head->next;
   while (p)
   {
       cout << p->data << ' ';
       p = p->next;
   }
   cout << endl;
}
int main() {
   int n;
   cin >> n;
   LinkList list;
   while (n--) {
       int x;
       cin >> x;
       list.LL_insert(list.len + 1, x);
   }
   list.LL_display();
   int in, data,del,get;
   cin >> in >> data;
   if (list.LL_insert(in, data) != -1) {
       list.LL_display();
   }
   cin >> in >> data;
   if (list.LL_insert(in, data) != -1) {
       list.LL_display();
   }
   cin >> del;
   if (list.LL_del(del) != -1) {
       list.LL_display();
   }
   cin >> del;
   if (list.LL_del(del) != -1) {
       list.LL_display();
   }
   cin >> get;
   list.LL_get(get);
   cin >> get;
   list.LL_get(get);
	return 0;
}