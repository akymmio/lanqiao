#include <iostream>
#include <vector>
#include <algorithm> //max_element
using namespace std;
//ģ��
int main(){
    vector<vector<int>> times;
    int N, K; //n���ڵ㣬k�ǳ����ڵ�
    vector<int> d(N + 1, INT_MAX / 2);              // �ڵ���(1->N)
    d[K] = 0;                                       // ��ʼ�ڵ㵽����Ϊ0
    // ����N-1���ɳڣ���Ϊ�������������·��������N-1����,ʹd[i]Ϊ��ʼ�ڵ㵽i�ڵ����̾���
    for (int i = 1; i <= N; i++) {
        for (vector<int> &time : times) {
            int u = time[0]; // ��ʼ�ڵ�
            int v = time[1]; // Ŀ��ڵ�
            int w = time[2]; // Ȩ��
            if (d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
		}
          int res=0;
         res=*max_element(d.begin()+1,d.end());
        return res==INT_MAX/2?-1:res;  

}
