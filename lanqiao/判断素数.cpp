#include <iostream>
using namespace std;
bool isPrime(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
int main()
{
  // 请在此输入您的代码
  int count=0;
  for(int i=1;i<100000;i++){
    if(isPrime(i)){
      count++;
      if(count==2019){
        cout<<i;
        return 0;
      }
    }
  }
  return 0;
}