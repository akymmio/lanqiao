#include <iostream>
using namespace std;

int main(){
    int card = 2021;//1µÄ¿¨Æ¬ÊýÁ¿
    int i = 1;
    while(1){
        int m = i;
        int count = 0;
        while(m){
            int temp = m % 10;
            if(temp==1){
                count++;
            }
            m /= 10;
        }
        card -= count;
        if(card<0){
            cout << --i;
            return 0;
        }
        i++;
    }
    return 0;
}