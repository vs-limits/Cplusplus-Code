#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    string key;
    getline(cin,s);
    cin >> key;
    int len = s.length();
    string res = "";
    int cnt = -1;
    for(int i=0;i<len;i++){
        char c = s[i];
        if(c == ' '){
            res += ' ';
            continue;
        }else{
            cnt ++;
        }
        if(c>='a'&&c<='z')
            c = (c-'a'+ key[cnt % key.length()] - 'a') % 26 +'a';
        else if(c>='A'&&c<='Z')
            c = (c-'A'+ key[cnt % key.length()] - 'a') % 26 +'A';
        res += c;
    }
    cout << res << endl;
}