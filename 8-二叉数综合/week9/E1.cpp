#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
   char data;
   TreeNode* left;
   TreeNode* right;
   TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// ���������������������#��ʾ�գ�
void createBiTree(TreeNode*& root) {
   char value;
   cin >> value;
   if (value == '#') {
       root = nullptr;
       return;
   }
   root = new TreeNode(value);
   createBiTree(root->left);
   createBiTree(root->right);
}

// ��������Ϣ�ṹ�壺�洢�����߶ȣ�������������ڵ㣨�ֵ�����С��
struct TreeInfo {
   int height;         // �����߶ȣ�������Ҷ�ӽڵ�߶�Ϊ0��
   TreeNode* deepestNode; // ����������Ľڵ㣨�ֵ�����С��
   TreeInfo(int h = 0, TreeNode* dn = nullptr) : height(h), deepestNode(dn) {}
};

// �ݹ麯�������������߶Ⱥ�����ڵ㣬������ȫ�������뼰�˵�
TreeInfo getHeightAndDeepest(TreeNode* root, int& maxEdgeDis, char& start, char& end) {
   if (root == nullptr) {
       return TreeInfo(-1, nullptr); // �սڵ�߶�Ϊ-1����������������������߶�
   }

   // �ݹ��ȡ����������Ϣ
   TreeInfo leftInfo = getHeightAndDeepest(root->left, maxEdgeDis, start, end);
   TreeInfo rightInfo = getHeightAndDeepest(root->right, maxEdgeDis, start, end);

   // ���㵱ǰ�����ĸ߶ȣ���������max(��/�������߶�) + 1
   int currHeight = max(leftInfo.height, rightInfo.height) + 1;

   // ȷ����ǰ����������ڵ㣨�ֵ�����С��
   TreeNode* currDeepest = root;
   if (leftInfo.height > rightInfo.height) {
       currDeepest = leftInfo.deepestNode;
   }
   else if (rightInfo.height > leftInfo.height) {
       currDeepest = rightInfo.deepestNode;
   }
   else {
       // ���������߶���ȣ�ѡ���ֵ�����С�Ľڵ㣨������������������ǰ�ڵ㣩
       char minChar = root->data;
       TreeNode* candidates[3] = { leftInfo.deepestNode, rightInfo.deepestNode, root };
       for (auto node : candidates) {
           if (node != nullptr && node->data < minChar) {
               minChar = node->data;
           }
       }
       // ����ѡ���������ڵ㣬�������������ǰ�ڵ㣨��֤�ֵ�����С��
       for (auto node : candidates) {
           if (node != nullptr && node->data == minChar) {
               currDeepest = node;
               break;
           }
       }
   }

   // ���㵱ǰ�ڵ��ֱ�������������������߶� + �������߶� + 2��������������ǰ�ڵ��1���ߣ�
   int currDiameter = leftInfo.height + rightInfo.height + 2;

   // ���ɵ�ǰ��ѡ�ڵ�ԣ�ȷ��start <= end���ֵ�����С��
   char newS = '\0', newE = '\0';
   if (leftInfo.deepestNode != nullptr && rightInfo.deepestNode != nullptr) {
       newS = min(leftInfo.deepestNode->data, rightInfo.deepestNode->data);
       newE = max(leftInfo.deepestNode->data, rightInfo.deepestNode->data);
   }
   else if (leftInfo.deepestNode != nullptr) {
       newS = min(leftInfo.deepestNode->data, root->data);
       newE = max(leftInfo.deepestNode->data, root->data);
   }
   else if (rightInfo.deepestNode != nullptr) {
       newS = min(root->data, rightInfo.deepestNode->data);
       newE = max(root->data, rightInfo.deepestNode->data);
   }
   else {
       // Ҷ�ӽڵ㣨��������Ϊ�գ�����ѡ��Ϊ����
       newS = newE = root->data;
       currDiameter = 0;
   }

   // ����ȫ�������뼰�˵�
   if (currDiameter > maxEdgeDis) {
       maxEdgeDis = currDiameter;
       start = newS;
       end = newE;
   }
   else if (currDiameter == maxEdgeDis) {
       // �ֵ���Ƚϣ����ȵ�һ���ڵ�С���ٵڶ����ڵ�С
       if (newS < start || (newS == start && newE < end)) {
           start = newS;
           end = newE;
       }
   }

   return TreeInfo(currHeight, currDeepest);
}

// �������������뼰��Ӧ�ڵ�
void MaxDistance(TreeNode*& root, int& dis, char& start, char& end) {
   dis = 0;
   start = end = '\0';
   if (root == nullptr) return;
   // ��ʼ��start��endΪ���ڵ㣨�������ڵ�����
   start = end = root->data;
   int maxEdgeDis = 0;
   getHeightAndDeepest(root, maxEdgeDis, start, end);
   dis = maxEdgeDis;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
       TreeNode* root = nullptr;
       createBiTree(root);

       int dis;
       char start, end;
       MaxDistance(root, dis, start, end);

       cout << dis << ":";
       if (dis > 0 && start != '\0' && end != '\0') {
           cout << " " << start << " " << end;
       }
       cout << "\n";
   }
   return 0;
}