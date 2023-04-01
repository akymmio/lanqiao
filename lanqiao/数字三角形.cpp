#include <iostream>
using namespace std;
int dp[105][105];
int g[105][105];
int main()
{
  // 请在此输入您的代码
  int n;
  cin >> n;
  for (int i =0; i < n;i++) {
      for (int j = 0; j <= i;j++) {
          cin >> g[i][j];
      }
  }
  dp[0][0] = g[0][0];
  for (int i = 1; i < n;i++) {
      for (int j = 0; j <= i;j++) {
          if (j ==0) {//往左走
              dp[i][j] = dp[i - 1][j]+g[i][j];
          }
          else{
              dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + g[i][j];
          }
      }
  }
  if(n%2){
      cout << dp[n-1][n / 2];
  }
  else{
      cout << max(dp[n-1][n/2],dp[n-1][n/2-1]);
  }
  return 0;
}