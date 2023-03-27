#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;

long long a[N], b[N];
int main() {
    int n, ma, mb;
    cin >> n >> ma;
    for (int i = 1; i <= ma; i++) {
        cin >> a[i];
    }
    cin >> mb;
    for (int i = 1; i <= mb; i++) {
        cin >> b[i];
    }
    long long ans = 0, jz = 1; // ����
    for (int i = 1; i <= ma; i++) {
        ans = (ans + (a[i] - b[i]) * jz) % mod;
        long long t = max(a[i], b[i]) + 1;
        if (t < 2)
            t = 2;
        jz = jz * t % mod;
    }
    cout << (ans + mod) % mod;
    return 0;
}
// ��ǰλ�õ�ʮ����ֵ������һλ����ֵ���Խ���
// ��λ������λ��ֵ����λ��������ֵ�Ĵ�С��ֻҪ�õ�λ�����ܵ�С