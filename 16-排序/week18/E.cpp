#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) :data(val), left(NULL), right(NULL) {};
};


void createTree(Node* &root,int num[],int len,int i) {
	queue<Node*> q;
	if (num[i] == -1 || i >= len) {
		root = NULL;
		return;
	}
	root = new Node(num[i]);
	q.push(root);
	i++;
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();
		if (i < len) {
			if (num[i] != -1) {
				cur->left = new Node(num[i]);
				q.push(cur->left);
			}
			else {
				cur->left = NULL;
			}
			i++;
		}
		if (i < len) {
			if (num[i] != -1) {
				cur->right = new Node(num[i]);
				q.push(cur->right);
			}
			else {
				cur->right = NULL;
			}
			i++;
		}
	}

}

void sort(Node* &root,int &check) {
	if (root->left != NULL && root->right != NULL) {
		if (root->data > root->left->data && root->data < root->right->data) {
			sort(root->left,check);
			sort(root->right,check);
			return;
		}
		else {
			check = 0;
			return;
		}
	}
	else if (root->left != NULL && root->right == NULL) {
		if (root->data > root->left->data) {
			sort(root->left, check);
		}
		else {
			check = 0;
			return;
		}
	}
	else if (root->left == NULL && root->right != NULL) {
		if (root->data < root->right->data) {
			sort(root->right, check);
		}
		else {
			check = 0;
			return;
		}
	}
	else if (root->left == NULL && root->right == NULL) {
		return;
	}
		
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* num = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		Node* root = NULL;
		createTree(root, num, n, 0);
		int check = 1;
		sort(root, check);
		if (check == 0) {
			cout << "false" << endl;
		}
		else if (check == 1) {
			cout << "true" << endl;
		}
	}
	return 0;
}