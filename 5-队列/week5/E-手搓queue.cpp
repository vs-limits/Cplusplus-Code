#include<iostream>
using namespace std;

class MyCircularQueue {
private:
    int* data;       // 存储队列元素的数组
    int size;    // 队列容量
    int front;       // 队头指针
    int rear;        // 队尾指针
    int count;       // 当前元素数量

public:
    // 构造器，设置队列长度为k
    MyCircularQueue(int k) {
        size = k;
        data = new int[k];
        front = 0;
        rear = 0;
        count = 0;
    }

    ~MyCircularQueue() {
        delete[] data;
    }

    // 从队首获取元素
    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    // 获取队尾元素
    int Rear() {
        if (isEmpty()) return -1;
        // 计算实际队尾位置
        int tail = (rear - 1 + size) % size;
        return data[tail];
    }

    // 向循环队列插入一个元素
    bool enQueue(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }

    // 从循环队列中删除一个元素
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }

    // 检查循环队列是否为空
    bool isEmpty() {
        return count == 0;
    }

    // 检查循环队列是否已满
    bool isFull() {
        return count == size;
    }
};

int main() {
    int op_num;
    int size;
    cin >> op_num >> size;
    MyCircularQueue myqueue(size);

    while (op_num--) {
        string op;
        cin >> op;

        if (op == "enQueue") {
            int num;
            cin >> num;
            cout << (myqueue.enQueue(num) ? "true" : "false") << endl;
        }
        else if (op == "Rear") {
            cout << myqueue.Rear() << endl;
        }
        else if (op == "Front") {
            cout << myqueue.Front() << endl;
        }
        else if (op == "deQueue") {
            cout << (myqueue.deQueue() ? "true" : "false") << endl;
        }
        else if (op == "isEmpty") {
            cout << (myqueue.isEmpty() ? "true" : "false") << endl;
        }
        else if (op == "isFull") {
            cout << (myqueue.isFull() ? "true" : "false") << endl;
        }
    }
    return 0;
}