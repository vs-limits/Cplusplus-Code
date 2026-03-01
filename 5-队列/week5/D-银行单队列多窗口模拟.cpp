#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
#include<climits>
using namespace std;

int main() {
   int n;
   cin >> n;
   int ALL = 0;
   double avg = 0;
   int MAX = 0;
   int last_finish = 0;

   queue<int> Wtime;
   queue<int> Rtime;

   for (int i = 0; i < n; i++) {
       int W, R;
       cin >> W >> R;
       Wtime.push(W);
       Rtime.push(R);
   }

   int k;
   cin >> k;
   int* run = new int[k];
   for (int i = 0; i < k; i++) run[i] = 0;

   while (!Wtime.empty() && !Rtime.empty()) {
       int T = Wtime.front();
       int P = Rtime.front();
       Wtime.pop();
       Rtime.pop();

       int min_index = 0;
       int min_time = run[0];
       for (int i = 1; i < k; i++) {
           if (run[i] < min_time) {
               min_time = run[i];
               min_index = i;
           }
       }

       int wait_time = 0;
       if (T < min_time) {
           wait_time = min_time - T;
       }

       run[min_index] = max(T, min_time) + P;

       ALL += wait_time;
       if (wait_time > MAX) {
           MAX = wait_time;
       }
       if (run[min_index] > last_finish) {
           last_finish = run[min_index];
       }
   }

   avg = static_cast<double>(ALL) / n;

   cout << fixed << setprecision(1) << avg << " ";
   cout << MAX << " " << last_finish << endl;

   delete[] run;
   return 0;
}