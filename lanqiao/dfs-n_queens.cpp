#include <iostream>
#include <cmath>
using namespace std;
int arr[10]; // 皇后放在i行j列
int sum = 0;
int n=0;

int check(int r, int c) {
    for (int i = 0; i < r; i++) { // 判断前面的行
        if (arr[i] ==c) {         // 同一列
            return 0;
        }
        // 对角线情况
        if (abs(i - r) == abs(arr[i] - c) && abs(r - i) < 3) {
            return 0;
        }
    }
    return 1;
}
void dfs(int r) { // 从第r行开始
    if (r == n) {
        sum++;
        return;
    }
    // 从列开始找
    for (int c = 0; c < n; c++) {
        if (check(r, c)) {
            arr[r] = c;
            dfs(r + 1);
            arr[r] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    cout << sum;
}