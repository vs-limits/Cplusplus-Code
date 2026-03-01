#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char value) : data(value), left(NULL), right(NULL) {}
};

void createBiTree(TreeNode*& root) {
    char value;
    cin >> value;
    if (value == '#') {
        root = NULL;
        return;
    }
    root = new TreeNode(value);
    createBiTree(root->left);
    createBiTree(root->right);
}

struct TreeInfo {
    int height;         // 子树高度（边数：叶子节点高度为0）
    TreeNode* deepestNode; // 子树中最深的节点（字典序最小）
    TreeInfo(int h = 0, TreeNode* dn = NULL) : height(h), deepestNode(dn) {}
};

TreeInfo getHeightAndDeepest(TreeNode* root, int& maxEdgeDis, char& start, char& end) {
    if (root == NULL) {
        return TreeInfo(-1, NULL);
    }

    // 递归获取左右子树信息
    TreeInfo leftInfo = getHeightAndDeepest(root->left, maxEdgeDis, start, end);
    TreeInfo rightInfo = getHeightAndDeepest(root->right, maxEdgeDis, start, end);

    // 计算当前子树的高度（边数）：max(左/右子树高度) + 1
    int currHeight = max(leftInfo.height, rightInfo.height) + 1;

    // 确定当前子树的最深节点（字典序最小）
    TreeNode* currDeepest = root;
    if (leftInfo.height > rightInfo.height) {
        currDeepest = leftInfo.deepestNode ? leftInfo.deepestNode : root;
    }
    else if (rightInfo.height > leftInfo.height) {
        currDeepest = rightInfo.deepestNode ? rightInfo.deepestNode : root;
    }
    else {
        // 左右高度相等：选择字典序最小的节点（左子树、右子树、当前节点）
        TreeNode* ln = leftInfo.deepestNode ? leftInfo.deepestNode : root;
        TreeNode* rn = rightInfo.deepestNode ? rightInfo.deepestNode : root;
        currDeepest = (ln->data < rn->data) ? ln : rn;
    }

    // 计算当前节点的直径（边数）：左右子树高度之和 + 2（空节点高度-1，确保叶子节点直径为0）
    int currDiameter = leftInfo.height + rightInfo.height + 2;
    if (currDiameter < 0) currDiameter = 0; // 叶子节点直径修正为0

    // 生成当前候选节点对（确保非空且字典序最小）
    char newS = root->data, newE = root->data;
    if (leftInfo.deepestNode && rightInfo.deepestNode) {
        // 左右子树均有最深节点：按字典序排序
        newS = min(leftInfo.deepestNode->data, rightInfo.deepestNode->data);
        newE = max(leftInfo.deepestNode->data, rightInfo.deepestNode->data);
    }
    else if (leftInfo.deepestNode) {
        // 仅左子树有最深节点：与当前节点组合
        newS = min(leftInfo.deepestNode->data, root->data);
        newE = max(leftInfo.deepestNode->data, root->data);
    }
    else if (rightInfo.deepestNode) {
        // 仅右子树有最深节点：与当前节点组合
        newS = min(root->data, rightInfo.deepestNode->data);
        newE = max(root->data, rightInfo.deepestNode->data);
    }
    // 叶子节点：newS和newE均为root->data（默认值）

    // 更新全局最大距离及端点
    if (currDiameter > maxEdgeDis) {
        maxEdgeDis = currDiameter;
        start = newS;
        end = newE;
    }
    else if (currDiameter == maxEdgeDis) {
        // 距离相等时，选择字典序最小的节点对（参考代码一的pair比较逻辑）
        if (make_pair(newS, newE) < make_pair(start, end)) {
            start = newS;
            end = newE;
        }
    }

    return TreeInfo(currHeight, currDeepest);
}

void MaxDistance(TreeNode*& root, int& dis, char& start, char& end) {
    dis = 0;
    start = end = '\0';
    if (root == NULL) return;
    // 初始化start和end为根节点（避免空指针访问，处理单节点树）
    start = end = root->data;
    int maxEdgeDis = 0;
    getHeightAndDeepest(root, maxEdgeDis, start, end);
    dis = maxEdgeDis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        TreeNode* root = NULL;
        createBiTree(root);

        int dis;
        char start, end;
        MaxDistance(root, dis, start, end);

        cout << dis << ":";
        // 距离>0时才输出节点，避免单节点树多余输出
        if (dis > 0 && start != '\0' && end != '\0') {
            cout << start << " " << end;
        }
        cout << "\n";
    }
    return 0;
}