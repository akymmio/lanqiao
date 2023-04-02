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
    for (int i = 2; i < 10000;i++) {//遍历素数
        if(isPrime(i)){
            for (int j = 1; j < 1000;j++) {//遍历d，公差
                for (int k = 1; k < 10;k++) {//遍历10个元素
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
//所有小于等差素数列的长度的素数的乘积就是该等差素数列的公差。 
//d=10,2*3*5*7=210