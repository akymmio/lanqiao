#include <iostream>
using namespace std;
bool judge(int x, int y) {
    if (abs(x - 0) + abs(y - 0) <= 2020 ||
        abs(x - 2020) + abs(y - 11) <= 2020 ||
        abs(x - 11) + abs(y - 14) <= 2020 ||
        abs(x - 2000) + abs(y - 2000) <= 2020) {
        return true;
    }
    return false;
}
int main() {
    int ans = 0;
    // 扩散后会出现负数，所以需要移点
    for (int i = 0 - 2020; i <= 2020 + 2020; i++) {
        for (int j = 0 - 2020; j <= 2020 + 2020; j++) {
            if (judge(i, j)) {
                ans++;
            }
        }
    }
    cout << ans;
}