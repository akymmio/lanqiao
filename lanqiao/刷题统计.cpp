#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a, b, n, day, week, last;
int main() {
    cin >> a >> b >> n;
    int temp = a * 5 + 2 * b; // һ����ˢ������
    week = n / temp;          // ��Ҫˢ����
    day += week * 7;
    last = n % temp; // ʣ�¼���
    int x = 1;
    while (last > 0) {
        if (x % 7 == 6 || x % 7 == 0) { // ֻ������7��һ�����ڣ�����x%6==0
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