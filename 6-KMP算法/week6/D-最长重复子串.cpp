#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class myString {
private:
  string mainstr; // ��
  int size;       // ������
  void GetNext(string p, int next[]) {
      next[0] = -1;
      int i = 0, j = -1;
      int len = p.length();
      while (i < len) {
          if (j == -1 || p[i] == p[j]) {
              i++;
              j++;
              next[i] = j;
          }
          else {
              j = next[j];
          }
      }
  }
  int KMPFind(string p, int pos, int next[]) {
      int i = pos, j = 0, len = p.length();
      while (i < size && j < len) {
          if (j == -1 || mainstr[i] == p[j]) {
              i++;
              j++;
          }
          else {
              j = next[j];
          }
      }
      if (j == len) {
          return i - j + 1;
      }
      else {
          return 0;
      }
  }
public:
  myString();
  ~myString();
  void SetVal(string sp);
  int KMPFindSubstr(string p, int pos);
  int maxString(string str);
};

myString::myString() {
  size = 0;
  mainstr = "";
}

myString::~myString() {
  size = 0;
  mainstr = "";
}

void myString::SetVal(string sp) {
  mainstr = "";
  mainstr.assign(sp);
  size = mainstr.length();
}

int myString::KMPFindSubstr(string p, int pos) {
  int L = p.length();
  int* next = new int[L];
  GetNext(p, next);
  int v = KMPFind(p, pos, next);
  delete[] next;
  return v;
}

int myString::maxString(string str) {
  int perlen = str.length();
  int max = -1;
  for (int i = 0; i < perlen; i++) {
      int len = str.length();
      int* next = new int[len+1];
      GetNext(str, next);
      for (int j = 0; j < len + 1; j++) {
          if (next[j] != 0 && next[j] > max) {
              max = next[j];
          }
      }

      str = str.substr(1, len + 1);

      if (max <= perlen / 2) {
          continue;
      }
      else {
          max = next[max];
      }
  }
  return max;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
      string s;
      cin >> s;
      myString ms;
      ms.SetVal(s);
      int result = ms.maxString(s);
      cout << result << endl;
  }
  return 0;
}