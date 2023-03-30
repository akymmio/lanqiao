#include <iostream>
using namespace std;
int ans = 0;
int vis[10][10] = {0};                            // 标记是否遍历过
int t[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // 移动
void dfs(int i, int j, int c) {
    if (c == 16) {
        ans++;
        return;
    }
    for (int k = 0; k < 4; k++) { // 遍历方向
        if (vis[i + t[k][0]][j + t[k][1]] == 0 && i + t[k][0] >= 1 &&
            i + t[k][0] <= 4 && j + t[k][1] >= 1 && j + t[k][1] <= 4) {
            vis[i + t[k][0]][j + t[k][1]] = 1;   // 标记已走
            dfs(i + t[k][0], j + t[k][1], c + 1); // c+1自带回溯
            vis[i + t[k][0]][j + t[k][1]] = 0;   // 回溯
        }
    }
    return;
}
int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            vis[i][j] = 1;
            dfs(i, j, 1); // 带有计数器
            vis[i][j] = 0;
        }
    }
    cout << ans;
    return 0;
}