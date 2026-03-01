//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//const int INF = 10000000;
//
//// 边结构体
//struct Edge {
//    int u, v, weight;
//};
//
//// 边比较函数
//bool compareEdges(const Edge& a, const Edge& b) {
//    return a.weight < b.weight;
//}
//
//class Graph {
//private:
//    int p_num;
//    string* point;
//    int** matrix;
//
//    // 查找顶点索引
//    int findVertexIndex(const string& v) {
//        for (int i = 0; i < p_num; i++) {
//            if (point[i] == v) return i;
//        }
//        return -1;
//    }
//
//    // 并查集查找
//    int findParent(int* parent, int i) {
//        if (parent[i] != i) {
//            parent[i] = findParent(parent, parent[i]);
//        }
//        return parent[i];
//    }
//
//    // 并查集合并
//    void unionSets(int* parent, int* rank, int x, int y) {
//        int xroot = findParent(parent, x);
//        int yroot = findParent(parent, y);
//
//        if (rank[xroot] < rank[yroot]) {
//            parent[xroot] = yroot;
//        }
//        else if (rank[xroot] > rank[yroot]) {
//            parent[yroot] = xroot;
//        }
//        else {
//            parent[yroot] = xroot;
//            rank[xroot]++;
//        }
//    }
//
//public:
//    void createGraph() {
//        cin >> p_num;
//        point = new string[p_num];
//        for (int i = 0; i < p_num; i++) {
//            cin >> point[i];
//        }
//
//        matrix = new int* [p_num];
//        for (int i = 0; i < p_num; i++) {
//            matrix[i] = new int[p_num];
//            for (int j = 0; j < p_num; j++) {
//                matrix[i][j] = 0;
//            }
//        }
//
//        int edge_num;
//        cin >> edge_num;
//        for (int i = 0; i < edge_num; i++) {
//            string start, end;
//            int weight;
//            cin >> start >> end >> weight;
//            int s_index = findVertexIndex(start);
//            int e_index = findVertexIndex(end);
//            if (s_index != -1 && e_index != -1) {
//                matrix[s_index][e_index] = weight;
//                matrix[e_index][s_index] = weight;
//            }
//        }
//    }
//
//    // Prim算法
//    void primMST(const string& start_p) {
//        bool* inMST = new bool[p_num];
//        int* key = new int[p_num];
//        int* parent = new int[p_num];
//
//        for (int i = 0; i < p_num; i++) {
//            inMST[i] = false;
//            key[i] = INF;
//            parent[i] = -1;
//        }
//
//        int start_index = findVertexIndex(start_p);
//        if (start_index == -1) return;
//
//        key[start_index] = 0;
//
//		Edge* prim_edges = new Edge[p_num - 1];
//        int edge_count = 0;
//		int total_weight = 0;
//
//        for (int count = 0; count < p_num; count++) {
//            // 找到key值最小的顶点
//            int min_key = INF;
//            int u = -1;
//
//            for (int i = 0; i < p_num; i++) {
//                if (!inMST[i] && key[i] < min_key) {
//                    min_key = key[i];
//                    u = i;
//                }
//            }
//
//            if (u == -1) break;
//            inMST[u] = true;
//
//            if (parent[u] != -1) {
//                prim_edges[edge_count].u = parent[u];
//                prim_edges[edge_count].v = u;
//                prim_edges[edge_count].weight = matrix[parent[u]][u];
//                total_weight += prim_edges[edge_count].weight;
//                edge_count++;
//            }
//
//            // 更新相邻顶点的key值
//            for (int v = 0; v < p_num; v++) {
//                if (matrix[u][v] != 0 && !inMST[v] && matrix[u][v] < key[v]) {
//                    key[v] = matrix[u][v];
//                    parent[v] = u;
//                }
//            }
//        }
//
//        // 输出结果
//        cout << total_weight << endl;
//        cout << "prim:" << endl;
//        for (int i = 0; i < edge_count; i++) {
//            cout << point[prim_edges[i].u] << " "
//                << point[prim_edges[i].v] << " "
//                << prim_edges[i].weight << endl;
//        }
//
//        delete[] inMST;
//        delete[] key;
//        delete[] parent;
//        delete[] prim_edges;
//    }
//
//    // Kruskal算法
//    void kruskalMST() {
//        // 计算总边数
//        int total_edges = 0;
//        for (int i = 0; i < p_num; i++) {
//            for (int j = i + 1; j < p_num; j++) {
//                if (matrix[i][j] != 0) {
//                    total_edges++;
//                }
//            }
//        }
//
//        // 分配边数组
//        Edge* edges = new Edge[total_edges];
//        int edge_index = 0;
//
//        // 收集所有边
//        for (int i = 0; i < p_num; i++) {
//            for (int j = i + 1; j < p_num; j++) {
//                if (matrix[i][j] != 0) {
//                    edges[edge_index].u = i;
//                    edges[edge_index].v = j;
//                    edges[edge_index].weight = matrix[i][j];
//                    edge_index++;
//                }
//            }
//        }
//
//        // 对边进行排序（冒泡排序）
//        for (int i = 0; i < total_edges - 1; i++) {
//            for (int j = 0; j < total_edges - i - 1; j++) {
//                if (edges[j].weight > edges[j + 1].weight) {
//                    Edge temp = edges[j];
//                    edges[j] = edges[j + 1];
//                    edges[j + 1] = temp;
//                }
//            }
//        }
//
//        // 并查集初始化
//        int* parent = new int[p_num];
//        int* rank = new int[p_num];
//        for (int i = 0; i < p_num; i++) {
//            parent[i] = i;
//            rank[i] = 0;
//        }
//
//        // 构建最小生成树
//        Edge* mst_edges = new Edge[p_num - 1];
//        int mst_count = 0;
//
//        for (int i = 0; i < total_edges && mst_count < p_num - 1; i++) {
//            int u_root = findParent(parent, edges[i].u);
//            int v_root = findParent(parent, edges[i].v);
//
//            if (u_root != v_root) {
//                mst_edges[mst_count] = edges[i];
//                mst_count++;
//                unionSets(parent, rank, u_root, v_root);
//            }
//        }
//
//        // 输出Kruskal算法结果
//        cout << "kruskal:" << endl;
//        for (int i = 0; i < mst_count; i++) {
//            cout << point[mst_edges[i].u] << " "
//                << point[mst_edges[i].v] << " "
//                << mst_edges[i].weight << endl;
//        }
//
//        delete[] edges;
//        delete[] parent;
//        delete[] rank;
//        delete[] mst_edges;
//    }
//
//    ~Graph() {
//        delete[] point;
//        for (int i = 0; i < p_num; i++) {
//            delete[] matrix[i];
//        }
//        delete[] matrix;
//    }
//};
//
//int main() {
//    Graph graph;
//    graph.createGraph();
//
//    string start_vertex;
//    cin >> start_vertex;
//
//    graph.primMST(start_vertex);
//    graph.kruskalMST();
//
//    return 0;
//}
