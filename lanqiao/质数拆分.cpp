#include <iostream>
using namespace std;
int p[2020];
int fg[2020];
int cnt = 0;//质数的个数
long long dp[2020];
void prime(){
    for (int i = 2; i <= 2019;i++) {
        if(!fg[i]){
            p[++cnt] = i;//记录质数
            for (int j = 2; j*i<= 2019;j++) {
                fg[j*i] = 1;//记录非质数
            }
        }
    }
}
int main(){
    prime();
    dp[0] = 1;
    for (int i = 1; i <= cnt;i++) {
        for (int j = 2019; j >= p[i];j--) {
            dp[j] = dp[j] + dp[j - p[i]];
        }
    }
    cout << dp[2019];
}