#include <iostream>
using namespace std;
int main() {
    // 请在此输入您的代码
    int n;
    cin >> n;
    int m = n;
    int c = 1;
    while (m) {
        m /= 3;
        c+=m;
    }
    cout << (n + c);
    return 0;
}