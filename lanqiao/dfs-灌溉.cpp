#include <iostream>
using namespace std;
int n, m, t, k;
int a[100][100];
int main() {
    cin >> n >> m >> t; // t为点的数量
    for (int i = 1; i <= t; i++) {
        cin >> a[i][0] >> a[i][1]; // 使得每一个点在数组中都是连续的
    }
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {     // 遍历nxm矩阵
            for (int c = 1; c <= t; c++) { // 遍历管道
                if (abs(i - a[c][0]) + abs(j - a[c][1]) <= k) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
