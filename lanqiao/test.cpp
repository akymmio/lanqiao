#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  // ���ڴ��������Ĵ���
  int count = 0;
  for (int i = 20220514;; i++) {
      string s = to_string(i);
      string a = s;   
      reverse(a.begin(), a.end());
      if (a == s) {
        if(count==2){
            cout << i;
            return 0;
        }
          count++;
      }
  }
  return 0;
}