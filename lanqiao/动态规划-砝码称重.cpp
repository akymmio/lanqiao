#include <bits/stdc++.h>//����ͷ�ļ�
using namespace std;
int main() {
    vector<vector<int>> dp(101, vector<int>(10001));
    int n, sum, ans;
    cin >> n;
    int f[n+1];
    for (int i = 1; i <=n; i++) {
        cin >> f[i]; // ÿ�����������
        sum += f[i]; // �����������
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) { // ��������
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = max(dp[i - 1][j],
                           max(dp[i - 1][j + f[i]], dp[i - 1][abs(j - f[i])]));
        }
    }
    for (int i = 1; i <= sum; i++) {
        if (dp[n][i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}