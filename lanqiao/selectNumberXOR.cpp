#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll n, m, x;
int dp[N];
map<ll, int> mp;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); // 加速（很关键！）
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        ll data;
        cin >> data;
        dp[i] = max(dp[i - 1],
                    mp[data ^ x]); // 看自己的左端口大还是前一个的左端口大
        mp[data] = i;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        if (dp[r] >= l) // 小区间包含，大区间一定包含
            cout << "yes\n";
        else {
            cout << "no\n";
        }
    }
    return 0;
}

// 小区间推大区间
// a^b=x 等价于 a^x=b;