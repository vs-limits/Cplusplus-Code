#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MaxW = 9999999;

class HuffNode{
public:
	int weight;//Ȩֵ
	int parent;//���ڵ�
	int leftchild;//����
	int rightchild;//�Һ���
};

class HuffTree {
private:
	void MakeTree(); // ����
	void SelectMin(int pos, int* s1, int* s2); // ѡ����С�������ڵ�
public:
	int len;
	int lnum;//Ҷ�ӽڵ����
	HuffNode* hufftree;//�洢��������
	string* huffcode;//�洢����������
	void MakeTree(int n, int wt[]);
	void Coding();
	void Destroy();
};

void HuffTree::MakeTree(int n,int wt[]) {
	int i;
	lnum = n;
	len = 2 * n - 1;
	hufftree = new HuffNode[len + 1];
	huffcode = new string[lnum + 1];
	for (i = 1; i <= n; i++) {
		hufftree[i].weight = wt[i - 1];
	}
	for (i = 1; i <= len; i++) {
		if (i > n) {
			hufftree[i].weight = 0;
		}
		hufftree[i].parent = 0;
		hufftree[i].leftchild = 0;
		hufftree[i].rightchild = 0;
	}
	MakeTree();
}

void HuffTree::SelectMin(int pos, int* s1, int* s2) {
	int w1, w2, i;
	w1 = w2 = MaxW;
	*s1 = *s2 = 0;
	for (i = 1; i <= pos; i++) {
		if (hufftree[i].weight < w1 && hufftree[i].parent == 0) {
			w2 = w1;
			*s2 = *s1;
			w1 = hufftree[i].weight;
			*s1 = i;
		}
		else if (hufftree[i].weight < w2 && hufftree[i].parent == 0) {
			w2 = hufftree[i].weight;
			*s2 = i;
		}
	}
}

void HuffTree::MakeTree() {
	int i, s1, s2;
	for (i = lnum + 1; i <= len; i++) {
		SelectMin(i - 1, &s1, &s2);
		hufftree[s1].parent = i;
		hufftree[s2].parent = i;
		hufftree[i].leftchild = s1;
		hufftree[i].rightchild = s2;
		hufftree[i].weight = hufftree[s1].weight + hufftree[s2].weight;
	}
}

void HuffTree::Destroy() {
	len = 0;
	lnum = 0;
	delete []hufftree;
	delete []huffcode;
}

void HuffTree::Coding() {
	char* cd = new char[lnum];
	cd[lnum - 1] = '\0';
	int i, c, f, start;
	for (i = 1; i <= lnum; i++) {
		start = lnum - 1;
		for (c = i, f = hufftree[i].parent; f != 0; c = f, f = hufftree[f].parent) {
			if (hufftree[f].leftchild == c) {
				cd[--start] = '0';
			}
			else {
				cd[--start] = '1';
			}
		}
		huffcode[i].assign(&cd[start]);
	}
	delete[]cd;
}

int main() {
	int t, n, i, j;
	int wt[800];
	HuffTree myHuff;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		for (j = 0; j < n; j++) {
			cin >> wt[j];
		}
		myHuff.MakeTree(n, wt);
		myHuff.Coding();
		for (j = 1; j <= n; j++) {
			cout << myHuff.hufftree[j].weight << '-';
			cout << myHuff.huffcode[j] << endl;
		}
		myHuff.Destroy();
	}
	return 0;
}