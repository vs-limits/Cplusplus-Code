//#include<iostream>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    int** Mix = new int* [n];
//    for (int i = 0; i < n; i++) {
//        Mix[i] = new int[n];
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> Mix[i][j];
//        }
//    }
//
//    // 添加自反性：每个顶点到自身可达
//    for (int i = 0; i < n; i++) {
//        Mix[i][i] = 1;
//    }
//
//    // 使用Warshall算法计算传递闭包
//    for (int k = 0; k < n; k++) {
//        for (int i = 0; i < n; i++) {
//            if (Mix[i][k]) {
//                for (int j = 0; j < n; j++) {
//                    if (Mix[k][j]) {
//                        Mix[i][j] = 1;
//                    }
//                }
//            }
//        }
//    }
//
//    // 将对角线中不在回路中的顶点设为0
//    for (int i = 0; i < n; i++) {
//        bool inCycle = false;
//        for (int j = 0; j < n; j++) {
//            if (i != j && Mix[i][j] && Mix[j][i]) {
//                inCycle = true;
//                break;
//            }
//        }
//        if (!inCycle) {
//            Mix[i][i] = 0;
//        }
//    }
//
//    // 输出传递闭包
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << Mix[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    // 释放内存
//    for (int i = 0; i < n; i++) {
//        delete[] Mix[i];
//    }
//    delete[] Mix;
//
//    return 0;
//}