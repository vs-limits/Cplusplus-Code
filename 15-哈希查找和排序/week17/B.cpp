//#include<iostream>
//#include<cmath>
//using namespace std;
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int m, n;
//        cin >> m >> n;
//        int* key = new int[n];
//        for (int i = 0; i < n; i++) {
//            cin >> key[i];
//        }
//
//        int* H = new int[m];
//        for (int i = 0; i < m; i++) {
//            H[i] = -1;
//        }
//
//        for (int i = 0; i < n; i++) {
//            int index = key[i] % 11;
//            int di = 1;
//            int cnt = 0;
//
//            if (H[index] == -1) {
//                H[index] = key[i];
//            }
//            else {
//                while (true) {
//                    int newIndex = (key[i] % 11 + (int)pow(-1, cnt) * (di * di)) % m;
//                    if (newIndex < 0) {
//                        newIndex = (newIndex % m + m) % m;
//                    }
//
//                    if (H[newIndex] == -1) {
//                        H[newIndex] = key[i];
//                        break;
//                    }
//                    else {
//                        if (cnt % 2 == 0) {
//                            cnt++;
//                        }
//                        else if (cnt % 2 == 1) {
//                            cnt++;
//                            di++;
//                        }
//                        if (cnt > 2 * m) {
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        for (int i = 0; i < m; i++) {
//            if (H[i] != -1) {
//                cout << H[i];
//            }
//            else if (H[i] == -1) {
//                cout << "NULL";
//            }
//            if (i != m - 1) {
//                cout << " ";
//            }
//            else if (i == m - 1) {
//                cout << endl;
//            }
//        }
//
//        int k;
//        cin >> k;
//        while (k--) {
//            int wait;
//            cin >> wait;
//            int di = 1;
//            int found = 0, cnt = 0, station = -1;
//            int Index = wait % 11;
//            int index = Index;
//
//            bool* visited = new bool[m];
//            for (int i = 0; i < m; i++) {
//                visited[i] = false;
//            }
//            int probeCnt = 0;
//
//            while (found != 1 && probeCnt < m) {
//                if (index >= m) {
//                    index = index % m;
//                }
//                else if (index < 0) {
//                    index = (index % m + m) % m;
//                }
//
//                cnt++;
//                if (H[index] == wait) {
//                    found = 1;
//                    station = index;
//                    break;
//                }
//                else if (H[index] == -1) {
//                    break;
//                }
//                else {
//                    visited[index] = true;
//                    index = (Index + (int)pow(-1, probeCnt) * (di * di));
//                    probeCnt++;
//                    if (probeCnt % 2 == 0) {
//                        di++;
//                    }
//                }
//            }
//
//            if (found == 0) {
//                cout << found << " " << cnt << endl;
//            }
//            else {
//                cout << found << " " << cnt << " " << station + 1 << endl;
//            }
//
//        }
//    }
//    return 0;
//}