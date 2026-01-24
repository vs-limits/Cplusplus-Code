#include<iostream>
#include<string>
using namespace std;
#define ok 0
#define error -1

class ListNode
{
public:
   char data;
   ListNode* next;
   ListNode* prev;
   ListNode() { next = NULL; prev = NULL; }
};

class LinkList
{
public:
   ListNode* head;
   int len;
   LinkList();
   ~LinkList();
   ListNode* LL_index(int i);
   int LL_get(int i);
   int LL_insert(int i, char item);
   int LL_del(int i);
   void LL_check(ListNode* p) {
       if (p == NULL || p == head) return;

       char ball = p->data;
       ListNode* left = p;
       ListNode* right = p;

       while (left->prev != head && left->prev->data == ball) {
           left = left->prev;
       }
       while (right->next != NULL && right->next->data == ball) {
           right = right->next;
       }
       int count = 1;
       ListNode* temp = left;
       while (temp != right) {
           count++;
           temp = temp->next;
       }

       if (count >= 3) {
           ListNode* prevNode = left->prev;
           ListNode* nextNode = right->next;

           // ����ɾ���ε�ǰ��ڵ�
           prevNode->next = nextNode;
           if (nextNode != NULL) {
               nextNode->prev = prevNode;
           }

           // ɾ���ڵ㲢���³���
           temp = left;
           while (temp != nextNode) {
               ListNode* toDelete = temp;
               temp = temp->next;
               delete toDelete;
               len--;
           }

           // ��������Ϊ�յ����
           if (len == 0) return;

           // ������������ɾ���ε�ǰһ���ڵ㿪ʼ���
           if (prevNode != head) {
               LL_check(prevNode);
           }
           // ���ǰһ����ͷ�ڵ㣬�����һ���ڵ�
           else if (nextNode != NULL) {
               LL_check(nextNode);
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
   ListNode* p = head;
   while (p != NULL)
   {
       ListNode* q = p;
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
   if (i < 1 || i > len + 1) {
       cout << "error" << endl;
       return error;
   }
   ListNode* p = LL_index(i - 1);
   ListNode* s = new ListNode();
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
   ListNode* p = LL_index(i - 1);
   ListNode* q = p->next;
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
   string s;
   cin >> s;
   LinkList list;
   for (int i = 0; i < n; i++) {
       list.LL_insert(i + 1, s[i]);
   }
   int t;
   cin >> t;
   while (t--) {
       int k;
       char c;
       cin >> k >> c;
       list.LL_insert(k + 1, c);
       ListNode* p = list.LL_index(k + 1);
       list.LL_check(p); 
       list.LL_display();
   }
   return 0;
}