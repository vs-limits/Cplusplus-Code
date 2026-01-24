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
   ListNode* LL_index(int i);
   int LL_insert(int i, int item);
   void LL_display();
	int LL_merge(ListNode* La, ListNode* Lb); // �ϲ�����������������
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
int LinkList::LL_merge(ListNode* La, ListNode* Lb) {
   ListNode* pa = La->next;
   ListNode* pb = Lb->next;
   LinkList listc;
   while (pa != NULL && pb != NULL) {
       if (pa->data <= pb->data) {
           listc.LL_insert(listc.len + 1, pa->data);
           pa = pa->next;
       }
       else {
           listc.LL_insert(listc.len + 1, pb->data);
           pb = pb->next;
       }
   }
   while (pa == NULL && pb != NULL) {
       listc.LL_insert(listc.len + 1, pb->data);
       pb = pb->next;
   }
   while (pb == NULL && pa != NULL) {
       listc.LL_insert(listc.len + 1, pa->data);
       pa = pa->next;
   }
	listc.LL_display();
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
   LinkList lista;
   while (n--) {
       int x;
       cin >> x;
       lista.LL_insert(lista.len + 1, x);
   }
   cin >> n;
   LinkList listb;
   while (n--) {
       int x;
       cin >> x;
       listb.LL_insert(listb.len + 1, x);
   }
   lista.LL_merge(lista.head, listb.head);
   return 0;
}