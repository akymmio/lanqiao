#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int d;
  cin>>d;
  string a1[10] = {"geng", "xin", "ren", "gui", "jia", "yi" , "bing", "ding", "wu", "ji"};
  string a2[12] = {"shen", "you", "xu", "hai", "zi", "chou", "yin", "mou", "chen", "si", "wu", "wei"};
  cout<<a1[d%10]<<a2[d%12];
  return 0;
}
