#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : data(value), left(NULL), right(NULL) {};
};

void createBiTree(TreeNode*& root, int* arr, int len, int i) {
	queue<TreeNode*> q;
	if (arr[i] == -1 || i >= len) {
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
			}
			else {
				current->left = NULL;
			}
			i++;
		}
		if (i < len) {
			if (arr[i] != -1) {
				current->right = new TreeNode(arr[i]);
				q.push(current->right);
			}
			else {
				current->right = NULL;
			}
			i++;
		}
	}
}

bool ifmirror(TreeNode* root1,TreeNode* root2) {
	if (root1->data == root2->data) {
		if(root1->left == NULL && root2->right == NULL && root1->right == NULL && root2->left == NULL) {
			return true;
		}
		else if (root1->left != NULL && root2->right != NULL && root1->right != NULL && root2->left != NULL) {
			return ifmirror(root1->left,root2->right) && ifmirror(root1->right,root2->left);
		}
		else if (root1->left == NULL && root2->right == NULL && root1->right != NULL && root2->left != NULL) {
			return ifmirror(root1->right, root2->left);
		}
		else if (root1->left != NULL && root2->right != NULL && root1->right == NULL && root2->left == NULL) {
			return ifmirror(root1->left, root2->right);
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		int* arr = new int[num];
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}
		TreeNode* root = NULL;
		createBiTree(root, arr, num, 0);
		if (root->left == NULL && root->right == NULL) {
			cout << "true" << endl;
		}
		else if(root->left != NULL && root->right != NULL){
			if (ifmirror(root->left, root->right)) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}
		else {
			cout << "false" << endl;
		}
		
	}
}