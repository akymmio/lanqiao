#include <iostream>
#include <cstring>
using namespace std;
const int ax[4] = {0, 0, 1, -1};
const int ay[4] = {1, -1, 0, 0};
const char dir[5] = {'R', 'L', 'D', 'U'};
int maze[60][60], mins[60][60];
char a[2000]; // 记录方位
int best;     // 记录步数
string ans;   // 记录a中方位路径

// 判断这个点是否越界，是否走过
bool judge(int x, int y) {
    return x > 0 && x <= 30 && y > 0 && y <= 50 && !maze[x][y];
}

void dfs(int x, int y, int pos) {
    if (pos > best)
        return; // 用步数剪枝
    if (x == 30 && y == 50) {
        string tmp;
        for (int i = 1; i < pos; ++i)
            tmp += a[i];
        if (pos < best) {
            ans = tmp;
            best = pos;
        } else if (pos == best && tmp < ans)
            ans = tmp;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int tempx = x + ax[i];
        int tempy = y + ay[i];
        if (judge(tempx, tempy) && pos + 1 <= mins[tempx][tempy]) // 步数剪枝
        {
            maze[tempy][tempy] = 1;
            mins[tempx][tempy] = pos + 1;
            a[pos] = dir[i];
            dfs(tempx, tempy, pos + 1);
            maze[tempx][tempy] = 0;
        }
    }
}
int main() {
    // 请在此输入您的代码
    memset(mins, 1 << 28, sizeof(mins));
    best = 1 << 28;
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= 50; ++j) {
            char t;
            cin >> t;
            maze[i][j] = t - '0';
        }
    }
    maze[1][1] = 1;
    dfs(1, 1, 1);
    cout << ans << endl;
    return 0;
}