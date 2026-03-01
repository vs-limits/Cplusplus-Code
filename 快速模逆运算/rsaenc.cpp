#include<iostream>
#include<string>
#include<iomanip>  // 用于格式化输出（补前导零）
using namespace std;

// 快速幂模运算：计算 (base^exp) % mod，避免溢出
long long fast_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;  // 初始取模，缩小数值
    while (exp > 0) {
        if (exp % 2 == 1) {  // exp为奇数时，乘入结果
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  // base平方
        exp /= 2;                   // exp减半（位运算优化）
    }
    return result;
}

int main() {
    int p, q, e;
    cin >> p >> q >> e;
    int n = p * q;  // 计算模数n
    getchar();      // 吸收输入后的换行符
    
    string m;
    getline(cin, m);  // 读取明文字符串
    int len = m.length();
    
    for (int i = 0; i < len; i += 2) {
        // 将两个字符转换为数字：(m[i]-'a')*100 + (m[i+1]-'a')
        int x = (m[i] - 'a') * 100 + (m[i + 1] - 'a');
        // 快速幂模计算加密结果
        long long c = fast_pow(x, e, n);
        // 格式化输出为四位（不足补零）
        cout << setw(4) << setfill('0') << c << " ";
    }
    
    return 0;
}