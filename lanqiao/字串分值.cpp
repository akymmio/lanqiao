#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string str;
    cin >> str;
    int len = str.size();
    int left, right;
    int sum = 0;
    char s;
    for (int i = 0; i < len; i++) {
        s = str[i];
        for (left = i - 1; left >= 0; left--) {
            if (str[left] == s)
                break;
        }
        for (right = i + 1; right < len; right++) {
            if (str[right] == s)
                break;
        }
        sum += (i - left) * (right - i);
    }
    cout << sum;
    // 请在此输入您的代码
    return 0;
}