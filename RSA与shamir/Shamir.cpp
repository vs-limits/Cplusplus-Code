#include<iostream>
using namespace std;

// 扩展欧几里得算法，用于求解ax + by = gcd(a,b)
int extendedgcd(int a,int m,int &x,int &y){
    // 基准情况：当m=0时，gcd=a，此时x=1, y=0
    if(m == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1,y1;
    // 递归调用，求解gcd(m, a%m)
    int gcd = extendedgcd(m,a%m,x1,y1);
    
    // 根据递归结果更新x和y的值
    x = y1;
    y = x1 - (a/m)*y1;

    return gcd;
}

// 求模逆元函数：在模b下求a的逆元
int modInverse(int a,int b){
    int x,y;
    // 使用扩展欧几里得算法求解
    int gcd = extendedgcd(a,b,x,y);

    // 如果a和b不互质，则逆元不存在
    if(gcd!= 1) return -1;
    // 返回正数的模逆元
    return (x%b + b)%b;
}

// 主函数
int main(){
    int p = 101,k = 4;  // 定义模数p=101，多项式次数k=4
    int x[4] = {1,2,3,4};  // 已知的x坐标点
    int y[4];  // 存储输入的y坐标值
    
    // 输入4个y值
    for(int i = 0;i < 4;i++){
        cin >> y[i];
    }

    int d = 0;  // 初始化共享密钥d
    
    // 使用拉格朗日插值法计算f(0)=d
    for(int i = 0;i < 4;i++){
        int fz = 1;  // 分子初始化为1
        int fm = 1;  // 分母初始化为1

        // 计算拉格朗日基函数的分子和分母
        for(int j = 0;j < 4;j++){
            if(j != i){
                // 分子：连乘(0 - x[j])
                fz = (fz * (0 - x[j] + p)) % p;  // 加p避免负数
                // 分母：连乘(x[i] - x[j])
                fm = (fm * (x[i] - x[j] + p)) % p;  // 加p避免负数
            }
        }

        // 计算分母的模逆元
        int inv = modInverse(fm,p);
        // 计算拉格朗日系数
        int lag = (fz * inv) % p;
        // 累加到共享密钥d
        d = (d + y[i] * lag) % p;
    }

    // 输出共享密钥d
    cout << d << endl;
    return 0;
}