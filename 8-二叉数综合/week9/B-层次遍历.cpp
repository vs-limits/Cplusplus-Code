#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct TreeNode {
   char data;
   TreeNode* left;
   TreeNode* right;
   TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// ����1��i��Ϊ���ô��ݣ���ȷ�������ṹ
void createBiTree(TreeNode*& root, const string& s, int& i) {
   if (i >= s.size()) return; // �����ַ������ȣ���ֹ�ݹ�

   if (s[i] == '#') {
       root = NULL;
       i++; // �����սڵ��i����
       return;
   }

   root = new TreeNode(s[i]); // �����ǿսڵ�
   i++; // ������ǰ�ڵ��i����
   createBiTree(root->right, s, i); // �ݹ鹹��������
   createBiTree(root->left, s, i); // �ݹ鹹��������
}

// ����2�����뵱ǰ�ڵ�����Һ��ӣ�������ѭ��
void Print(TreeNode* root, queue<TreeNode*>& Q) {
   if (root == nullptr) return;
   Q.push(root);
   while (!Q.empty()) {
       TreeNode* current = Q.front(); // ��ǰ�����Ľڵ�
       cout << current->data;
       Q.pop();

       // ���뵱ǰ�ڵ�����Һ��ӣ����Ǹ��ڵ�ģ�
       if (current->left != nullptr) Q.push(current->left);
       if (current->right != nullptr) Q.push(current->right);
   }
   cout << endl;
}

int main() {
   int t;
   cin >> t;
   while (t--) {
       TreeNode* root = nullptr;
       queue<TreeNode*> Q;
       string s;
       cin >> s;
       int i = 0;
       createBiTree(root, s, i); // ����i������
       Print(root, Q);
   }
   return 0;
}