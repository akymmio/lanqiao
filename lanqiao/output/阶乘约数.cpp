#include <iostream>
using namespace std;
int p[100];
int main(){
    //�Գ���
    //ͳ��n!�������������ֵĴ���
    for (int i = 2; i <= 100;i++) {
        int n = i;
        for (int j = 2; j * j <= n;j++) {
            while(n%j==0){
                p[j]++;
                n /= j;
            }
        } 
        if(n>1) p[n]++;//n����Ϊ����
    }
    long long ans = 1;
    for (int i = 2; i <= 100;i++) {
        if(p[i])
            ans *= (p[i]+1);
    }
    cout << ans << endl;
    return 0;
}
//���ù�ʽ��Լ������ = (a1 + 1)(a2 + 1)����(ak + 1) a�Ǹ��������ݣ����ֵĴ���