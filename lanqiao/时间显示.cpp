#include <iostream>
using namespace std;
int main(){
    long long int t;
    cin >> t;
    t = t % (24*60*60*1000);//除去完整多少天后剩余多少毫秒
    int h = t / (60 * 60 * 1000) % 24;//除去完整天，剩下几个小时
    int m = t/(60*1000)%60;//除去完整的小时后，剩下多少分钟
    int s = t / (1000) % 60;//剩下多少秒
    printf("%02d:%02d:%02d",h,m,s);//多余位置补上0，不是空格
    return 0;
}