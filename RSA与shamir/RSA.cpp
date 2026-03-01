#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int findGCD(unsigned int n1, unsigned int n2) {
        unsigned int i, gcd = 1;
        /* 计算最大公约数 */
        while(n2 != 0){
            i = n2;
            n2 = n1 % n2;
            n1 = i;
        }
        gcd = n1;
        return gcd;
}

unsigned int powMod(unsigned int a, unsigned int b, unsigned int n) {
        unsigned long long x = 1, y = a;
        while (b != 0) {
            if (b & 1) x = (x * y) % n; //二进制比较                        
            y = (y * y) % n;
            b >>= 1;//右移一位
            printf("%llu\n",x);
        }
        return x % n;
}

int main(int argc, char* argv[]) {
        unsigned int p, q;
        unsigned int n, phin;
        unsigned int e = 0; // 公钥
        unsigned int d = 0; // 私钥 
        unsigned int data = 3, cipher;

        scanf("%u %u", &p, &q);
        n = p * q;

        phin = (p - 1) * (q - 1);

        for (e = 5; e <= 100; e++) {
            if (findGCD(phin, e) == 1) break;
        }
        
        for (d = e + 1; d <= phin; d++) {
            if ( ((d * e) % phin) == 1) break;
        }
        /* 利用模幂函数powMod计算密文 */
        cipher = powMod(data, e, n);

        printf("%u %u %u\n", e, d ,cipher);

        return 0;
}