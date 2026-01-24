#include<iostream>
using namespace std;
#define ok 0
#define error -1

// ������㶨��
class ListNode
{
public:
   char data;
   ListNode* next;
   ListNode* prev;
   ListNode() { next = NULL; prev = NULL; }
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
   int LL_insert(int i, char item); // ����ֵitem�����i��λ��
   int LL_del(int i);              // ɾ����i�����
   int LL_check(ListNode* p) {
       if (p == NULL || p->next == NULL) return ok;
       char ball = p->data;
       ListNode* left = p;
       ListNode* right = p;

       while (left->prev != NULL && left->prev->data == ball) {
           left = left->prev;
       }
       while (right->next != NULL && right->next->data == ball) {
           right = right->next;
       }
       int count = 1;
       ListNode* bNode = left;
       while (bNode != right->next) {
           count++;
           bNode = bNode->next;
       }
       if (count >= 3) {
           ListNode* start = left->prev;
           ListNode* end = right->next;
           start->next = end;//���м�Ͽ�����������ͬ��ɫ����
           if (end != NULL) {
               end->prev = start;
           }
           bNode = left;
           while (bNode != end) {
               ListNode* temp = bNode;
               bNode = bNode->next;
               delete temp;
               len--;
           }
       }
   }
   void LL_display() {
       ListNode* p = head->next;
       if (p == NULL) {
           cout << "-" << endl;
       }
       else {
           while (p != NULL) {
               cout << p->data;
               p = p->next;
           }
           cout << endl;
       }
   }
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
int LinkList::LL_insert(int i, char item) {
   if (i < 1 || i >len + 1) { 
       cout << "error" << endl;
       return error; 
   }
   ListNode* p, * s;
   p = LL_index(i - 1);
   s = new ListNode();
   s->data = item;
   s->next = p->next;
   s->prev = p;
   if (p->next) {
       p->next->prev = s;
   }
   p->next = s;
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
   q = p->next;
   p->next = q->next;
   if (q->next) {
       q->next->prev = p;
   }
   delete q;
   len--;
   return ok;
}
int main() {
   int n;
   cin >> n;
   LinkList list;
   while (n--) {
       char x;
       cin >> x;
       list.LL_insert(list.len + 1, x);
   }
   int num;
   cin >> num;
   while (num--) {
       int place, ch;
       cin >> place >> ch;
       list.LL_insert(place + 1, ch);
       ListNode* p = list.LL_index(place + 1);
       list.LL_check(p);
       list.LL_display();
   }
   return 0;
}