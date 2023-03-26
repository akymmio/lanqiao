#include <iostream>
#include <cmath>
using namespace std;
int arr[10]; // �ʺ����i��j��
int sum = 0;
int n=0;

int check(int r, int c) {
    for (int i = 0; i < r; i++) { // �ж�ǰ�����
        if (arr[i] ==c) {         // ͬһ��
            return 0;
        }
        // �Խ������
        if (abs(i - r) == abs(arr[i] - c) && abs(r - i) < 3) {
            return 0;
        }
    }
    return 1;
}
void dfs(int r) { // �ӵ�r�п�ʼ
    if (r == n) {
        sum++;
        return;
    }
    // ���п�ʼ��
    for (int c = 0; c < n; c++) {
        if (check(r, c)) {
            arr[r] = c;
            dfs(r + 1);
            arr[r] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    cout << sum;
}