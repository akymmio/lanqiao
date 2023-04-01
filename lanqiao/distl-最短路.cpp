#include <iostream>
#include <cstring> //memset
using namespace std;
const int N = 21, n = 19; // 19个字母
int dist[N];              // 已知到点的最短路
int g[N][N];
bool vis[N];
void add(int a, int b, int c) { g[a][b] = g[b][a] = c; } // 添加边

int diskt() {
    memset(dist, 0x3f, sizeof(dist)); // 相当于初始化无穷大
    dist[1] = 0;                      // 一开始最短路为0；
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) { // i到j的距离
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                t = j; // 标记距离从i出发距离最短的点
            }
        }
        for (int j = 1; j < n; j++) {
            dist[j] = min(dist[j], dist[t] + g[i][j]); // t算是前一个节点
        }
        vis[t] = true;
    }
}
