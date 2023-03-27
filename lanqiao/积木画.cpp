#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
typedef long long ll;
int f[N];
int main() {
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    for (int i = 4; i <= n; i++) {
        f[i] = (2 * f[i - 1] % mod + f[i - 3] % mod) % mod;
    }
    cout << f[n];
    return 0;
}