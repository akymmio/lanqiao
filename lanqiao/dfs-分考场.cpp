
#include <iostream>
#include <string.h> //meset();
using namespace std;
int room[10001][10001]; // 教师
int rel[101][101];      // 关系
int ans = INT_MAX;
int n, m;

void dfs(int num, int kc) {
    if (kc >= ans)
        return;
    if (num > n) {
        ans = kc;
    } else {
        for (int i = 1; i <= kc; i++) { // 遍历考场
            int k = 0;
            while (room[i][k] &&
                   rel[num][room[i][k]] ==
                       0) { // 同一间教室的不同位置，这个人和这个位置有无关系
                k++;
            }
            if (room[i][k] == 0) {
                room[i][k] = num;
                dfs(num + 1, kc); // 下一个人，考场
                room[i][k] = 0;
            }
        }
        room[kc + 1][0] = num; // 去下一个考场
        dfs(num + 1, kc + 1);  // 递归
        room[kc + 1][0] = 0;   // 回溯
    }
}
int main() {
    memset(rel, 0, sizeof(rel));
    memset(room, 0, sizeof(room));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        rel[a][b] = 1;
        rel[b][a] = 1;
    }
    dfs(1, 1);
    cout << ans;
}