#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
int main() {
    // 请在此输入您的代码
    int n;
    cin >> n;
    unordered_set<int> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (m.count(a[i])) {
            a[i]++;
        }
        m.insert(a[i]);
    }
    for (auto i : m) {
        cout << i << " ";
    }
    system("pause");
    return 0;
}