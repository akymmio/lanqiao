#include <iostream>
using namespace std;
int dp[100][100];
int a[100][100];
int main()
{
  // 请在此输入您的代码
  int n;
  cin >> n;
  for (int i = 1; i <= n;i++) {
      for (int j = 1; j <= i;j++) {
          cin >> a[i][j];
      }
  }

    for (int i = 2; i <= n;i++) {
      for (int j = 1; j <= i;j++) {
          dp[i][j] += max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
      }
  }
  if(n%2==0){
      cout << dp[n-1][n/2+1];
  }
  else{
      cout << max(dp[n][n/2],dp[n][n/2+1]);
  }
  return 0;
}