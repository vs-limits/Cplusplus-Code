#include<iostream>
using namespace std;

#define ok 0
#define error -1

// ������㶨��
class ListNode
{
public:
   int ratio;
   int index;
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
   int LL_insert(int i, int ra, int in); // ����ֵitem�����i��λ��
   int LL_del(int i);              // ɾ����i�����
   void LL_display();              // ���������������
   void LL_add(ListNode* q, ListNode* p); // ����q�뵱ǰ������ӣ�����������
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
int LinkList::LL_insert(int i, int ra, int in) {
   if (i < 1 || i >len + 1) {
       cout << "error" << endl;
       return error;
   }
   ListNode* p, * s;
   p = LL_index(i - 1);
   s = new ListNode();
   s->next = p->next;
   p->next = s;
   s->ratio = ra;
   s->index = in;
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
   bool first = true;

   while (p != NULL)
   {
       if (p->ratio == 0) {
           p = p->next;
           continue;
       }

       if (!first && p->ratio != 0) {
           cout << " + ";
       }
       else if (!first && p->ratio < 0) {
           cout << " ";
       }

       if (p->index == 0) {
           if (p->ratio < 0) {
               cout << "(" << p->ratio << ")";
           }
           else {
               cout << p->ratio;
           }
       }
       else {
           if (p->ratio == 1) {
               cout << "1";
           }
           else if (p->ratio == -1) {
               cout << "(-1)";
           }
           else if (p->ratio < 0) {
               cout << "(" << p->ratio << ")";
           }
           else {
               cout << p->ratio;
           }
           if (p->index < 0) {
               cout << "x^(" << p->index << ")";
           }
           else if (p->index == 1) {
               cout << "x^1";
           }
           else {
               cout << "x^" << p->index;
           }
       }

       first = false;
       p = p->next;
   }

   if (first) {
       cout << "0";
   }
   cout << endl;
}
void LinkList::LL_add(ListNode* q, ListNode* p) {
   LinkList* temp = new LinkList();
   ListNode* p1 = p; // ��ǰ�����ĵ�һ���ڵ�
   ListNode* p2 = q; // ���������ĵ�һ���ڵ�

   // �鲢����ķ�ʽ�ϲ���������ʽ
   while (p1 != NULL && p2 != NULL) {
       if (p1->index == p2->index) {
           int sum = p1->ratio + p2->ratio;
           if (sum != 0) {
               temp->LL_insert(temp->len + 1, sum, p1->index);
           }
           p1 = p1->next;
           p2 = p2->next;
       }
       else if (p1->index < p2->index) {
           temp->LL_insert(temp->len + 1, p1->ratio, p1->index);
           p1 = p1->next;
       }
       else {
           temp->LL_insert(temp->len + 1, p2->ratio, p2->index);
           p2 = p2->next;
       }
   }

   while (p1 != NULL) {
       temp->LL_insert(temp->len + 1, p1->ratio, p1->index);
       p1 = p1->next;
   }

   while (p2 != NULL) {
       temp->LL_insert(temp->len + 1, p2->ratio, p2->index);
       p2 = p2->next;
   }

   temp->LL_display();
}

int main() {
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       LinkList* p = new LinkList();
       while (n--) {
           int ratio, index;
           cin >> ratio >> index;
           p->LL_insert(p->len + 1, ratio, index);
       }
       p->LL_display();
       cin >> n;
       LinkList* q = new LinkList();
       while (n--) {
           int ratio, index;
           cin >> ratio >> index;
           q->LL_insert(q->len + 1, ratio, index);
       }
       q->LL_display();
       p->LL_add(q->head->next, p->head->next);
   }
   return 0;
}