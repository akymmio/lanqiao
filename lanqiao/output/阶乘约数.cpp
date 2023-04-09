#include <iostream>
using namespace std;
int p[100];
int main(){
    //试除法
    //统计n!中所有素数出现的次数
    for (int i = 2; i <= 100;i++) {
        int n = i;
        for (int j = 2; j * j <= n;j++) {
            while(n%j==0){
                p[j]++;
                n /= j;
            }
        } 
        if(n>1) p[n]++;//n自身为素数
    }
    long long ans = 1;
    for (int i = 2; i <= 100;i++) {
        if(p[i])
            ans *= (p[i]+1);
    }
    cout << ans << endl;
    return 0;
}
//利用公式：约数个数 = (a1 + 1)(a2 + 1)……(ak + 1) a是该素数的幂（出现的次数