#include <iostream>
using namespace std;
int n, m, t, k;
int a[100][100];
int main() {
    cin >> n >> m >> t; // tΪ�������
    for (int i = 1; i <= t; i++) {
        cin >> a[i][0] >> a[i][1]; // ʹ��ÿһ�����������ж���������
    }
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {     // ����nxm����
            for (int c = 1; c <= t; c++) { // �����ܵ�
                if (abs(i - a[c][0]) + abs(j - a[c][1]) <= k) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
