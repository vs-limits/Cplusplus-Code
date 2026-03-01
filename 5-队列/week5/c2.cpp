//#include <bits/stdc++.h>
//using namespace std;
//
//queue<int> groupOrder;
//unordered_map<int, int> ElementToGroup;
//queue<int> group[11];
//bool groupIsInQueue[11];
//
//int main() {
//    int t;
//    cin >> t;
//    for (int i = 0; i < t; i++) {
//        int n;
//        cin >> n;
//        for (int j = 0; j < n; j++) {
//            int x;
//            cin >> x;
//            ElementToGroup[x] = i;
//        }
//    }
//    bool hasDequeue = false;
//    string op;
//    while (cin >> op && op != "STOP") {
//        if (op == "ENQUEUE") {
//            int x;
//            cin >> x;
//            int groupNum;
//            groupNum = ElementToGroup[x];
//            group[groupNum].push(x);
//            if (!groupIsInQueue[groupNum]) {
//                groupOrder.push(groupNum);
//                groupIsInQueue[groupNum] = true;
//            }
//        }
//        else if (op == "DEQUEUE") {
//            if (groupOrder.empty()) continue;
//            int x = group[groupOrder.front()].front();
//            group[groupOrder.front()].pop();
//            if (group[groupOrder.front()].empty()) {
//                groupIsInQueue[groupOrder.front()] = false;
//                groupOrder.pop();
//
//            }
//            if (hasDequeue)cout << " " << x;
//            else cout << x;
//            hasDequeue = true;
//        }
//    }
//    cout << endl;
//
//    return 0;
//}