#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.length();
    int Upper = 0;
    int Lower = 0;
    int Digit = 0;
    int Special = 0;
    if(len >= 8 && len <= 16){
        for(int i = 0;i < len;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                Lower = 1;
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                Upper = 1;
            }else if(s[i] >= '0' && s[i] <= '9'){
                Digit = 1;
            }else if(s[i] == '~' || s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^'){
                Special = 1;
            }
        }
        if(Upper + Lower + Digit + Special >= 3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}