#include<iostream>
#include<climits>
using namespace std;

struct node {
   int data;
   node* left;
   node* right;
   node(int value) :data(value), left(NULL), right(NULL) {};
};

void createTree(node*& p, int* mid, int* post, int n, int& min) {
   if (n == 0) {
       p = NULL;
       return;
   }
   p = new node(post[n - 1]);
   int i;
   for (i = 0; mid[i] != post[n-1];i++);
   createTree(p->left, mid, post, i, min);
   createTree(p->right, mid + i + 1, post + i, n - i - 1, min);
   if (p->left == NULL && p->right == NULL && min > p->data) {
       min = p->data;
   }
}

int main() {
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       int* mid = new int[n];
       int* post = new int[n];
       int min = INT_MAX;
       for (int i = 0; i < n; i++) {
           cin >> mid[i];
       }
       for (int i = 0; i < n; i++) {
           cin >> post[i];
       }
       node* root = NULL;
       createTree(root, mid, post, n, min);
       cout << min << endl;
   }
}