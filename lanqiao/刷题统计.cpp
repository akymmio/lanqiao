#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a, b, n, day, week, last;
int main() {
    cin >> a >> b >> n;
    int temp = a * 5 + 2 * b; // 一星期刷题数量
    week = n / temp;          // 需要刷几周
    day += week * 7;
    last = n % temp; // 剩下几天
    int x = 1;
    while (last > 0) {
        if (x % 7 == 6 || x % 7 == 0) { // 只能求余7，一个星期，不能x%6==0
            last -= b;
        } else {
            last -= a;
        }
        day++;
        x++;
    }
    cout << day;
    return 0;
}