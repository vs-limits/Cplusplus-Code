#include<iostream>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char value) { data = value; left = NULL; right = NULL; }
};

class queue {
private:
	struct Node {
		TreeNode* value;
		Node* next;
		Node(TreeNode* x):value(x),next(NULL){}
	};
	Node* front;
	Node* tail;
public:
	queue() {
		front = NULL;
		tail = NULL;
	}
	~queue() {
		while (!empty()) {
			pop();
		}
	}
	bool empty() {
		if (front == NULL) {
			return true;
		}
		return false;
	}
	void push(TreeNode* &root) {
		Node* node = new Node(root);
		if (tail != NULL) {
			tail->next = node;
		}
		tail = node;
		if (front == NULL) {
			front = node;
		}
	}
	void pop() {
		if (empty()) return;
		Node* temp = front;
		front = front->next;
		if (front == NULL) {
			tail = NULL;
		}
		delete temp;
	}
	TreeNode* Front() {
		return front->value;
	}
};

void createBiTree(TreeNode*& root,const string& s,int& i) {
	if (i >= s.size()) return;
	if (s[i] == '#') {
		root = NULL;
		i++;
		return;
	}
	root = new TreeNode(s[i]);
	i++;
	createBiTree(root->right,s,i);
	createBiTree(root->left,s,i);
}

void preOrder(TreeNode*& root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void InOrder(TreeNode*& root) {
	if (root == NULL) return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}

void postOrder(TreeNode*& root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void LevelOrder(TreeNode*& root) {
	if (root == NULL) return;
	queue Q;
	Q.push(root);
	while (!Q.empty()) {
		cout << Q.Front()->data << " ";
		TreeNode* temp = Q.Front();
		Q.pop();
		if (temp->left != NULL) Q.push(temp->left);
		if (temp->right != NULL) Q.push(temp->right);
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i = 0;
		TreeNode* root = NULL;
		createBiTree(root,s,i);
		if (root == NULL) {
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
		}
		else {
			preOrder(root);
			cout << endl;
			InOrder(root);
			cout << endl;
			postOrder(root);
			cout << endl;
			LevelOrder(root);
		}
	}
	return 0;
}