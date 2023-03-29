// 学会对修改sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> a;
int sum(int a) {
    int ans = 0;
    while (a) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}
int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    sort(a.begin(), a.end(), [](int a, int b) { return sum(a) < sum(b); });
    cout << a[m - 1];
    return 0;
}