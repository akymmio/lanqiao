#include <iostream>
#include <vector>
using namespace std;
vector<int> a[100005];

int dfs(int node) {
    int count = 0; // ͳ��ÿһ��ڵ�ĺ���
    for (int i = 0; i < a[node].size(); i++) {
        count = max(count,dfs(a[node][i])); // ��ȣ�ͬһ���һֱ�������ӣ��Ѻ������ķ�����ײ�,�ظ�����
    }
    return count + a[node].size();
}
int main() {
    int n, t;
    cin >> n;
    for (int i = 2; i <= n; i++) { // �׽ڵ�Ϊ1��
        cin >> t;
        a[t].push_back(i);
    }
    cout << dfs(1);
    return 0;
}