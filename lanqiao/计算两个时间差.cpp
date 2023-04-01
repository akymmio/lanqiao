#include <iostream>
using namespace std;
int main(){
    int months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int km = 0;
    int week = 6;
    for (int i = 2000; i <= 2020;i++) {
          if((i%400==0) || (i%4==0 && i%100!=0)){
              months[2] = 29;
          }
          else{
              months[2] = 28;
          }
          for (int month = 1; month <= 12;month++) {
              for (int day = 1; day <=months[month];day++) {
                km++;
                if(week==8)
                week = 1;
                if(week==6 || day==1)
                    km++;
                    week++;
                    if(i==2020 && month==10 && day==1){
                        cout << km;
                        return 0;
                    }
              }
          }
    }
    return 0;
}