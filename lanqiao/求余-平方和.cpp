#include <iostream>
using namespace std;
int main(){
    long long int ans = 0;
    for (int i = 1; i <=2019;i++) {
        int  j = i;
        while(j){
            if(j % 10==2 || j % 10==1 ||j % 10==0 ||j % 10==9 ){
                ans += i*i;
                break;
            }  
            j /= 10;
        }
      
    }
    cout << ans;
}