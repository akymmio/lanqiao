#include <iostream>
#include <vector>
#include <algorithm> //max_element
using namespace std;
//模板
int main(){
    vector<vector<int>> times;
    int N, K; //n个节点，k是出发节点
    vector<int> d(N + 1, INT_MAX / 2);              // 节点是(1->N)
    d[K] = 0;                                       // 起始节点到自身为0
    // 进行N-1论松弛，因为任意两点间的最短路径最多包含N-1条边,使d[i]为起始节点到i节点的最短距离
    for (int i = 1; i <= N; i++) {
        for (vector<int> &time : times) {
            int u = time[0]; // 起始节点
            int v = time[1]; // 目标节点
            int w = time[2]; // 权重
            if (d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
		}
          int res=0;
         res=*max_element(d.begin()+1,d.end());
        return res==INT_MAX/2?-1:res;  

}
