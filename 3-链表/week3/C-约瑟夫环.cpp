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
int main() {
   int t;
   cin >> t;
   while (t--) {
       int N, K, S;
       cin >> N >> K >> S;
       LinkList list;
       for (int i = 1; i <= N; i++) {
           list.LL_insert(i, i);
       }

       if (N > 0) {
           ListNode* last = list.LL_index(list.len);
           ListNode* first = list.head->next;
           last->next = first;

           ListNode* p = last;
           ListNode* c = first;

           for (int i = 1; i < S; i++) {
               p = c;
               c = c->next;
           }

           while (list.len > 1) {
               for (int i = 1; i < K; i++) {
                   p = c;
                   c = c->next;
               }
               cout << c->data << " ";
               p->next = c->next;
               ListNode* temp = c;
               c = c->next;
               delete temp;
               list.len--;
           }
           
           cout << c->data << endl;
           delete c;
           list.head->next = NULL;
       }
   }
   return 0;
}