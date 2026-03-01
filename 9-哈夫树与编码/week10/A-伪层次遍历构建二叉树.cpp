#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : data(value), left(NULL), right(NULL) {};
};

void createBiTree(TreeNode*& root,int* arr,int len,int i) {
	queue<TreeNode*> q;
	if(arr[i] == -1 || i >= len) {
		root = NULL;
		return;
	}
	root = new TreeNode(arr[i]);
	q.push(root);
	i++;
	while (!q.empty()) {
		TreeNode* current = q.front();
		q.pop();
		if (i < len) {
			if (arr[i] != -1) {
				current->left = new TreeNode(arr[i]);
				q.push(current->left);
			} else {
				current->left = NULL;
			}
			i++;
		}
		if (i < len) {
			if (arr[i] != -1) {
				current->right = new TreeNode(arr[i]);
				q.push(current->right);
			} else {
				current->right = NULL;
			}
			i++;
		}
	}
}

void preOrder(TreeNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void InOrder(TreeNode* root) {
	if (root == NULL) return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}

void PostOrder(TreeNode* root) {
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		int* arr = new int[num];
		for(int i = 0; i < num; i++) {
			cin >> arr[i];
		}
		TreeNode* root = NULL;
		createBiTree(root,arr,num,0);
		preOrder(root);
		cout << endl;
		InOrder(root);
		cout << endl;
		PostOrder(root);
		cout << endl;
		cout << endl;
	}
}