#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for (int i = 2; i * i <= n;i++) {
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int sum=1;
    for (int i = 2; i < 10000;i++) {//��������
        if(isPrime(i)){
            for (int j = 1; j < 1000;j++) {//����d������
                for (int k = 1; k < 10;k++) {//����10��Ԫ��
                    if(isPrime(i+j*k)){
                        sum++;
                    }
                    else{
                        sum = 1;
                        break;
                    }
                    if(sum==10){
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
//����С�ڵȲ������еĳ��ȵ������ĳ˻����ǸõȲ������еĹ�� 
//d=10,2*3*5*7=210