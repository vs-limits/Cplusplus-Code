#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main() {
   int t;
   cin >> t;

   unordered_map<int, int> EleminGroup;
   for (int i = 0; i < t; i++) {
       int num;
       cin >> num;
       for (int j = 0; j < num; j++) {
           int x;
           cin >> x;
           EleminGroup[x] = i;
       }
   }

   queue<int> Grouporder; 
   queue<int> myQ[10];
   int* GroupinQ = new int[10]; 

   for (int i = 0; i < 10; i++) {
       GroupinQ[i] = -1; 
   }

   string op;
   cin >> op;
   bool firstOutput = true;

   while (op != "STOP") {
       if (op == "ENQUEUE") {
           int x;
           cin >> x;
           int group = EleminGroup[x];

           if (GroupinQ[group] == -1) {
               Grouporder.push(group);
               GroupinQ[group] = group;
           }

           myQ[group].push(x);
       }
       else if (op == "DEQUEUE") {
           if(Grouporder.empty()) {
               cin >> op;
               continue;
			}
           int group = Grouporder.front();

           if (firstOutput) {
               cout << myQ[group].front();
               firstOutput = false;
           }
           else {
               cout << " " << myQ[group].front();
           }

           myQ[group].pop();

           if (myQ[group].empty()) {
               Grouporder.pop();
               GroupinQ[group] = -1;
           }
       }
       cin >> op;
   }
   return 0;
}