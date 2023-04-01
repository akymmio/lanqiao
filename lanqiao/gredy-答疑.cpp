#include <iostream>
#include <algorithm>
using namespace std;
struct sum {
    int sum1; // 发消息后的时间
    int sum2; // 总时间
};
bool cmp(sum a, sum b) { return a.sum2 <= b.sum2; } // 结构体排序重载
int main() {
    int n;
    cin >> n;
    sum num[1001];
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        num[i].sum1 = c;
        num[i].sum2 = a + b + c;
    }
    long long ans = 0;
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) { // 类似与前缀和
        ans += num[i].sum2 * (n - i) - num[i].sum1;
    }
    cout << ans;
    return 0;
}