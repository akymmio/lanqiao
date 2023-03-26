#include <iostream>
using namespace std;
const int N = 1e5 + 10;
struct cholocate {
    int len;
    int wid;
    int maxEdge; // 最长边
} c[N];

int main() {
    int n, k, maxe;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i].len >> c[i].wid;
        c[i].maxEdge = max(c[i].len, c[i].wid);
        maxe = max(maxe, c[i].maxEdge);
    }
    int l = 1, r = maxe, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int e1 = c[i].len / mid;
            int e2 = c[i].wid / mid;
            cnt += e1 * e2; // 可以切割为多少块
        }
        if (cnt >= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}