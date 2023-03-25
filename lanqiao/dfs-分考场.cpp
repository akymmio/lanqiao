
#include <iostream>
#include <string.h> //meset();
using namespace std;
int room[10001][10001]; // ��ʦ
int rel[101][101];      // ��ϵ
int ans = INT_MAX;
int n, m;

void dfs(int num, int kc) {
    if (kc >= ans)
        return;
    if (num > n) {
        ans = kc;
    } else {
        for (int i = 1; i <= kc; i++) { // ��������
            int k = 0;
            while (room[i][k] &&
                   rel[num][room[i][k]] ==
                       0) { // ͬһ����ҵĲ�ͬλ�ã�����˺����λ�����޹�ϵ
                k++;
            }
            if (room[i][k] == 0) {
                room[i][k] = num;
                dfs(num + 1, kc); // ��һ���ˣ�����
                room[i][k] = 0;
            }
        }
        room[kc + 1][0] = num; // ȥ��һ������
        dfs(num + 1, kc + 1);  // �ݹ�
        room[kc + 1][0] = 0;   // ����
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