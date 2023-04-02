#include<iostream>
#include <cstring>
using namespace std;    
int n,i;
typedef long long LL;
// 计算c(a,b);
LL c(int a,int b){
    LL res=1;
    for (int i = a, j = 1; j <= b;i--,j++) {
        res = res * i / j;
        if(res>n){
            return res;//大于n已经无意义了
        }
    }
    return res;
}
bool check(int k){
    int l=2*k,r=max(l,n);//l（l,k都是下标）是斜行第一个元素c的下标，k是层数也就是上标
    
    while(l<r){
        int mid = l + r >> 1;
        if (c(mid, k) >= n) r=mid;
        else{
            l = mid + 1;
        }
    }
    if(c(r,k)!=n){//再次验证
        return false;
    }
    //r下标，k上标，求出此元素前面多少个元素，+1求出自己第几次出现
    cout << 1ll*(r + 1) * r / 2 + k + 1; // 1LL是为了计算时，把int类型转化为longlong型
    return true;
}

int main(){
    cin>>n;
    for (i = 16;;i--) {
        if(check(i)){
            break;
        }
    }
    return 0;
}