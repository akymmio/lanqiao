#include <iostream>
using namespace std;
int main() {
    // ���ڴ��������Ĵ���
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