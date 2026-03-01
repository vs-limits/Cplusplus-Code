// #include<iostream>
// #include<string>
// using namespace std;

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    char s[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string pair;
    cin >> pair;
    int n = pair.length();
    
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < 26; i++) {
            if(s[i] == pair[j]) {
                for(int k = i; k < 25; k++) {
                    s[k] = s[k+1];
                }
                s[25] = pair[j];
                break;
            }
        }
    }

    char arr[5][5];
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            arr[i][j] = s[i*5+j];
        }
    }
    
    string str;
    cin >> str;
    
    // 加密处理
    string cipher = "";
    int len = str.length();
    int idx = 0;
    
    while(idx < len) {
        if(idx == len - 1) {
            cipher += str[idx];
            break;
        }
        
        char a = str[idx];
        char b = str[idx+1];
        
        if(a == b) {
            cipher += a;
            cipher += b;
            idx += 2;
            continue;
        }
        
        int a_row = -1, a_col = -1;
        int b_row = -1, b_col = -1;
        
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(arr[i][j] == a) {
                    a_row = i;
                    a_col = j;
                }
                if(arr[i][j] == b) {
                    b_row = i;
                    b_col = j;
                }
            }
        }
        
        if(a_row == -1 || a_col == -1 || b_row == -1 || b_col == -1) {
            cipher += a;
            cipher += b;
            idx += 2;
            continue;
        }
        
        if(a_row == b_row || a_col == b_col) {
            cipher += b;
            cipher += a;
        } 

        else {
            cipher += arr[a_row][b_col];
            cipher += arr[b_row][a_col];
        }
        
        idx += 2;
    }
    
    cout << cipher << endl;
    return 0;
}

// int main(){
//     char s[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//     string pair;
//     cin >> pair;
//     int n = pair.length();
//     for(int i = 0;i < 26;i++){
//         for(int j = 0;j < n;j++){
//             if(s[i] == pair[j]){
//                 char temp = s[i];
//                 int sta = i;
//                 while(sta != 25){
//                     s[sta] = s[sta+1];
//                     sta++;
//                 }
//                 s[25] = temp;
//             }
//         }
//     }
//     char arr[5][5];
//     for(int i = 0;i < 5;i++){
//         for(int j = 0;j < 5;j++){
//             arr[i][j] = s[i*5+j];
//         }
//     }
//     string str;
//     cin >> str;
    
// }