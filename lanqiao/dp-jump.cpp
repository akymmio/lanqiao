#include <iostream>
#include <algorithm>
using namespace std;
int dp[105][105];
int g[105][105];
int dir[9][2] = {{0, -1},  {0, -2}, {0, -3},  {-1, 0}, {-1, -1},
                 {-1, -2}, {-2, 0}, {-2, -1}, {-3, 0}}; //
int n, m;
int INF = 0x3f3f3f3f; // 定义无穷大
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = g[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;
            for (auto [dx, dy] : dir) { // 同时遍历两个下标
                int nx = dx + i, ny = dy + j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    dp[i][j] = max(dp[i][j], dp[nx][ny]);
                }
                dp[i][j] += g[i][j];
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}