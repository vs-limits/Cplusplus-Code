#include<iostream>
#include<string>
using namespace std;
class myString
{
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
  string matched_Prefix_Postfix(string str);
};
myString::myString()
{
  size = 0;
  mainstr = "";
}
myString::~myString()
{
  size = 0;
  mainstr = "";
}
void myString::SetVal(string sp)
{
  mainstr = "";
  mainstr.assign(sp);
  size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
  int i;
  int L = p.length();
  int* next = new int[L];
  GetNext(p, next);
  int v = -1;
  v = KMPFind(p, pos, next);
  delete[]next;
  return v;
}
string myString::matched_Prefix_Postfix(string str) {
  string res = "";
  int max = 0;
  int len = str.length();
  int* next = new int[len + 1];
  GetNext(str, next);
  for (int i = 0; i < len + 1; i++) {
		cout << next[i] << ' ';
  }
  cout << endl;
  max = next[len];
  if (max == 0) {
      res = "empty";
      return res;
  }
  else {
      res = str.substr(0, max);
      return res;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
      string s;//����
      cin >> s;
      myString ms;
      ms.SetVal(s);
      string res = ms.matched_Prefix_Postfix(s);
      cout << res << endl;
  }
}