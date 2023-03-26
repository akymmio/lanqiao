// flood fill
#include <iostream>
using namespace std;
const int N = 1010;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool st[N][N];
char s[N][N];
int total, brink;
int n;
void dfs(int x, int y) {
    st[x][y] = true; // 访问过
    total++;         // 岛屿面积
    // 找边
    for (int i = 0; i < 4; i++) {
        if (s[x + dx[i]][y + dy[i]] == '.') {
            brink++; // 只要接触海洋就为边，跳出
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= n)
            continue;
        if (s[tx][ty] == '#' && !st[tx][ty]) {
            dfs(tx, ty);
        }
    }
}
int main() {

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#' && !st[i][j]) {
                total = brink = 0;
                dfs(i, j);
                if (total == brink)
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}