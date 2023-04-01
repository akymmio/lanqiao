#include <iostream>
using namespace std;
int main() {
    string str[30];
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        cin >> str[i];
    }
    // 右
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 49; j++) {
            for (int k = j + 1; k < 50; k++) { // 50细节
                if (str[i][j] < str[i][k])
                    ans++;
            }
        }
        // 防止越界
        if (i != 29) {

            for (int j = 0; j < 50; j++) {
                // 正下方
                for (int k = i + 1; k < 30; k++) {
                    if (str[i][j] < str[k][j])
                        ans++;
                }
                // 右下角
                for (int k = i + 1; k < 30; k++) {
                    if (j != 49 && (j + (k - i)) < 50 &&
                        str[i][j] <str[k][j +(k - i)]) // 对角线，从上往下和从左往右都一样
                        ans++;
                }
                // 左下角
                for (int k = i + 1; k < 30; k++) {
                    if (j != 0 && (j - (k - i)) >= 0 &&
                        str[i][j] !=str[k][j -(k -i)]) // 对角线（可反转），从上到下不是递增，从左到右就可能递增，只要位置不同就行
                        ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}