//#include<iostream>
//using namespace std;
//
//class MyCircularQueue {
//	private:
//	struct Node {
//		int data;
//		Node* next;
//		Node(int val) : data(val), next(nullptr) {}
//	};
//	Node* front;
//	Node* rear;
//	int size;
//public:
//	MyCircularQueue(int k) {
//		size = k;
//	}; //构造器，设置队列长度为k;
//	int Front() {
//		if (isEmpty()) return -1;
//		return front->data;
//	};//从队首获取元素。如果队列为空，返回 - 1;
//	int Rear() {
//		if (isEmpty()) return -1;
//		return rear->data;
//	}; //获取队尾元素。如果队列为空，返回 - 1 。
//	bool enQueue(int value) {
//		front = new Node(value);
//		if (isEmpty()) {
//			rear = front;
//		}
//		else {
//			rear->next = front;
//			rear = front;
//		}
//		return true;
//	}; //向循环队列插入一个元素。如果成功插入则返回真。
//	bool deQueue() {
//		front = front->next;
//		if (front == nullptr) rear = nullptr;
//		return true;
//	}; //从循环队列中删除一个元素。如果成功删除则返回真。
//	bool isEmpty() {
//		if (front == rear && front == nullptr) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}; //检查循环队列是否为空。
//	bool isFull() {
//		if(front == rear && front != nullptr) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}; //检查循环队列是否已满。
//};
//
//int main() {
//	int op_num;
//	int size;
//	cin >> op_num >> size;
//	MyCircularQueue myqueue(size);
//	while (op_num--) {
//		string op;
//		cin >> op;
//		if (op == "enQueue") {
//			int num;
//			cin >> num;
//			cout << myqueue.enQueue(num) << endl;
//		}
//		else if (op == "Rear") {
//			int num = myqueue.Rear();
//			cout << num << endl;
//		}
//		else if (op == "Front") {
//			int num = myqueue.Front();
//			cout << num << endl;
//		}
//		else if (op == "deQueue") {
//			cout << myqueue.deQueue() << endl;
//		}
//		else if (op == "isEmpty") {
//			cout << myqueue.isEmpty() << endl;
//		}
//		else if (op == "isFull") {
//			cout << myqueue.isFull() << endl;
//		}
//	}
//}