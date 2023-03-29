#include <iostream>
#include <vector>
using namespace std;
vector<int> a[100005];

int dfs(int node) {
    int count = 0; // 统计每一层节点的孩子
    for (int i = 0; i < a[node].size(); i++) {
        count = max(count,dfs(a[node][i])); // 深度，同一层的一直往下连接，把孩子最多的放在最底层,重复操作
    }
    return count + a[node].size();
}
int main() {
    int n, t;
    cin >> n;
    for (int i = 2; i <= n; i++) { // 首节点为1，
        cin >> t;
        a[t].push_back(i);
    }
    cout << dfs(1);
    return 0;
}