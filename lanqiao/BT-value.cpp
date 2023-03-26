// 完全二叉树的权值

/*求深度、求每一层的和、最后一层需要考虑特殊处理*/
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int maxx = -N;
int main() {
    int n,m, lev=0, sum, flag, i, j;
      cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    m = n;
    while (m) {
        m/= 2;
        lev++;
    } // 求深度
    for (i = 1; i < lev; i++) {
        sum = 0;
        int t1 = pow(2, i - 1), t2 = pow(2, i);
        for (j = t1; j <= t2 - 1; j++) { // 遍历本层的节点
            sum += a[j];
        }
        if (sum > maxx) {
            maxx = sum;
            flag = i;
        }
    }
    sum = 0;
    for (int i = pow(2, lev - 1); i <= n; i++) {
        sum += a[i];
    }
    if (sum > maxx)
        flag = lev;
    cout << flag;
    // 最后一层特殊处理
    return 0;
}