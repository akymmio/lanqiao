#include<iostream>
#include <cstring>
using namespace std;    
int n,i;
typedef long long LL;
// ����c(a,b);
LL c(int a,int b){
    LL res=1;
    for (int i = a, j = 1; j <= b;i--,j++) {
        res = res * i / j;
        if(res>n){
            return res;//����n�Ѿ���������
        }
    }
    return res;
}
bool check(int k){
    int l=2*k,r=max(l,n);//l��l,k�����±꣩��б�е�һ��Ԫ��c���±꣬k�ǲ���Ҳ�����ϱ�
    
    while(l<r){
        int mid = l + r >> 1;
        if (c(mid, k) >= n) r=mid;
        else{
            l = mid + 1;
        }
    }
    if(c(r,k)!=n){//�ٴ���֤
        return false;
    }
    //r�±꣬k�ϱ꣬�����Ԫ��ǰ����ٸ�Ԫ�أ�+1����Լ��ڼ��γ���
    cout << 1ll*(r + 1) * r / 2 + k + 1; // 1LL��Ϊ�˼���ʱ����int����ת��Ϊlonglong��
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