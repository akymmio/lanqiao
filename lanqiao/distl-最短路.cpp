#include <iostream>
#include <cstring> //memset
using namespace std;
const int N = 21, n = 19; // 19����ĸ
int dist[N];              // ��֪��������·
int g[N][N];
bool vis[N];
void add(int a, int b, int c) { g[a][b] = g[b][a] = c; } // ��ӱ�

int diskt() {
    memset(dist, 0x3f, sizeof(dist)); // �൱�ڳ�ʼ�������
    dist[1] = 0;                      // һ��ʼ���·Ϊ0��
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) { // i��j�ľ���
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                t = j; // ��Ǿ����i����������̵ĵ�
            }
        }
        for (int j = 1; j < n; j++) {
            dist[j] = min(dist[j], dist[t] + g[i][j]); // t����ǰһ���ڵ�
        }
        vis[t] = true;
    }
}
