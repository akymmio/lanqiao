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
    cin.tie(0); // ���٣��ܹؼ�����
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        ll data;
        cin >> data;
        dp[i] = max(dp[i - 1],
                    mp[data ^ x]); // ���Լ�����˿ڴ���ǰһ������˿ڴ�
        mp[data] = i;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        if (dp[r] >= l) // С���������������һ������
            cout << "yes\n";
        else {
            cout << "no\n";
        }
    }
    return 0;
}

// С�����ƴ�����
// a^b=x �ȼ��� a^x=b;