#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int x, a, b, c;
int grow[2000];  // 作物生长时间
bool have[2000]; // 是否有种子
int dis[2000];   // 杂交时间
struct node {
    int a, b;
};
vector<node> v[2000];

// 深度搜索
int dfs(int now) {   // 当前想要找到的作物
    if (have[now]) { // 存在该作物，直接反对杂交时间
        return dis[now];
    } else {
        for (int i = 0; i < v[now].size(); i++) { // 遍历所有能生成now种子的组合
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
        cin >> grow[i]; // 作物生长时间
    }
    memset(dis, 127, sizeof(dis));
    for (int i = 1; i <= m; i++) { // 初始时的种子
        cin >> x;
        have[x] = 1; // 有该种子
        dis[x] = 0;  // 不需要杂交
    }
    node demo;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        demo.a = a;
        demo.b = b;
        v[c].push_back(demo); // c下标的数组存储着含有ab的结构体
    }
    int ans = dfs(t);
    cout << ans;
}