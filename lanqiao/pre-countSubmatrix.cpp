// 前缀和+双指针，统计子矩阵
#include <iostream>
using namespace std;
const int N = 510;
typedef long long ll;
ll dp[N][N];
ll a[N][N];
ll n, m, k;
ll sum(int x1, int y1, int x2, int y2) {
    return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] +
           dp[x1 - 1][y1 - 1]; // 通过前缀和求得的区间的值
}
void solve() {
    int val;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> val;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                       a[i][j]; // 求前缀和
        }
    }
    ll ans = 0;
    for (int i = 1; i <=n; i++) {
        for (int j = i; j <=n; j++) {             // 行
            for (int l = 1, r = 1; r <= m; r++) { // 双指针遍历列
                while (l <= r && sum(i, l, j, r) > k)
                    l++;
                ans += r - l + 1;
            }
        }
    }
    cout << ans;
}
int main() {
    
    solve();

    return 0;
}