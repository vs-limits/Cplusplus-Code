//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* next;
//	Node(int val){ 
//		data = val; 
//		next = NULL; 
//	};
//};
//
//class H {
//private:
//	Node* head[11];
//public:
//	H() {
//		for (int i = 0; i < 11; i++) {
//			head[i] = NULL;
//		}
//	}
//
//	int hash(int key) {
//		return key % 11;
//	}
//
//	void insert(int key) {
//		int index = hash(key);
//		Node* newNode = new Node(key);
//		newNode->next = head[index];
//		head[index] = newNode;
//	}
//
//	void search(int key) {
//		int index = hash(key);
//		int cnt = 0;
//		Node* cur = head[index];
//
//		while (cur != NULL) {
//			cnt++;
//			if (cur->data == key) {
//				cout << index << " " << cnt << endl;
//				return;
//			}
//			cur = cur->next;
//		}
//
//		insert(key);
//		cout << "error" << endl;
//	}
//};
//
//int main() {
//	int n;
//	while (cin >> n) {
//		H list;
//		for (int i = 0; i < n; i++) {
//			int x;
//			cin >> x;
//			list.insert(x);
//		}
//		int t;
//		cin >> t;
//		while (t--) {
//			int x;
//			cin >> x;
//			list.search(x);
//		}
//	}
//	
//}