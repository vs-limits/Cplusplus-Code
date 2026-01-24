#include<iostream>
using namespace std;

#define ok 0
#define error -1

// 链表结点定义
class ListNode
{
public:
    int ratio;
    int index;
    ListNode* next;
    ListNode() { next = NULL; }
};
// 带头结点的单链表类定义
class LinkList
{
public:
    ListNode* head;
    int len;
    // 操作定义
    LinkList();
    ~LinkList();
    ListNode* LL_index(int i);      // 返回第i个结点的指针，如果不存在返回NULL
    int LL_insert(int i, int ra,int in); // 把数值item插入第i个位置
    int LL_del(int i);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
	void LL_add(ListNode* q,ListNode* p); // 链表q与当前链表相加，返回新链表
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
int LinkList::LL_insert(int i, int ra,int in) {
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
    bool flag = true;
    while (p != NULL)
    {
        if (p->ratio == 0) {
            p = p->next;
            continue;
        }
        if (!flag && p->ratio != 0) {
            cout << " + ";
        }

        if (p->ratio > 0 && p->index == 0) {
            cout << p->ratio;
        }else if(p->ratio < 0 && p->index == 0) {
            cout << "(" << p->ratio << ")";
		}
        else if (p->ratio >0 && p->index > 0) {
            cout << p->ratio << "x^" << p->index;
        }
        else if (p->ratio > 0 && p->index < 0) {
            cout << p->ratio << "x^(" << p->index << ")";
        }
        else if (p->ratio < 0 && p->index < 0) {
            cout << "(" << p->ratio << ")x^(" << p->index << ")";
        }
        else if (p->ratio < 0 && p->index > 0) {
            cout << "(" << p->ratio << ")x^" << p->index;
        }
        flag = false;
        p = p->next;
    }
    cout << endl;
}
void LinkList::LL_add(ListNode* q,ListNode* p) {
    LinkList* temp = new LinkList();
    while (p != NULL && q != NULL) {
        if (p->index == q->index) {
            if (p->ratio + q->ratio != 0) {
				temp->LL_insert(temp->len + 1, p->ratio + q->ratio, p->index);
                p = p->next;
                q = q->next;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
        else if (p->index > q->index) {
            temp->LL_insert(temp->len + 1, q->ratio, q->index);
            q = q->next;
        }
        else if (p->index < q->index) {
            temp->LL_insert(temp->len + 1, p->ratio, p->index);
            p = p->next;
        }
    }
    while (p != NULL) {
		temp -> LL_insert(temp->len + 1, p->ratio, p->index);
        p = p->next;
    }
    while (q != NULL) {
        temp -> LL_insert(temp->len + 1, q->ratio, q->index);
        q = q->next;
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