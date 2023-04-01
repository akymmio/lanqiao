#include <iostream>
#include <algorithm>
using namespace std;
struct sum {
    int sum1; // ����Ϣ���ʱ��
    int sum2; // ��ʱ��
};
bool cmp(sum a, sum b) { return a.sum2 <= b.sum2; } // �ṹ����������
int main() {
    int n;
    cin >> n;
    sum num[1001];
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        num[i].sum1 = c;
        num[i].sum2 = a + b + c;
    }
    long long ans = 0;
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) { // ������ǰ׺��
        ans += num[i].sum2 * (n - i) - num[i].sum1;
    }
    cout << ans;
    return 0;
}