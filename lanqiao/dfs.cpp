#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int x, a, b, c;
int grow[2000];  // ��������ʱ��
bool have[2000]; // �Ƿ�������
int dis[2000];   // �ӽ�ʱ��
struct node {
    int a, b;
};
vector<node> v[2000];

// �������
int dfs(int now) {   // ��ǰ��Ҫ�ҵ�������
    if (have[now]) { // ���ڸ����ֱ�ӷ����ӽ�ʱ��
        return dis[now];
    } else {
        for (int i = 0; i < v[now].size(); i++) { // ��������������now���ӵ����
            node p = v[now][i];
            dis[now] = min(dis[now],
                           max(dfs(p.a), dfs(p.b)) + max(grow[p.a], grow[p.b]));
        }
        have[now] = true;
        return dis[now];
    }
}
int main() {
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= n; i++) {
        cin >> grow[i]; // ��������ʱ��
    }
    memset(dis, 127, sizeof(dis));
    for (int i = 1; i <= m; i++) { // ��ʼʱ������
        cin >> x;
        have[x] = 1; // �и�����
        dis[x] = 0;  // ����Ҫ�ӽ�
    }
    node demo;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        demo.a = a;
        demo.b = b;
        v[c].push_back(demo); // c�±������洢�ź���ab�Ľṹ��
    }
    int ans = dfs(t);
    cout << ans;
}