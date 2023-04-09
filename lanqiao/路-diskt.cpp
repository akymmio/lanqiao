#include <iostream>
#include <vector>
#include <algorithm> //max_element
#include <cstring> //memset
using namespace std;
const int N = 21, n = 19; // 19个字母
int dist[N];              // 已知到点的最短路
int g[N][N];              //当前节点路径长度
bool vis[N];              //节点访问标记
void add(int a, int b, int c) { g[a][b] = g[b][a] = c; } // 添加边和权值

int diskt() {
    memset(dist, 0x3f, sizeof(dist)); // 相当于初始化无穷大
    dist[1] = 0;                      // 起点到节点的最短路
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) {//
                t = j; 
            }
        }
        for (int j = 1; j < n; j++) {
            dist[j] = min(dist[j], dist[t] + g[i][j]); // 起点到节点i的距离+节点i到j=起点到j的距离
        }
        vis[t] = true;
    }
}


//leetcode网络延迟时间
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf=INT_MAX/2;
        vector<vector<int>> g(n,vector<int>(n,inf));//x,y下标表示边，对应二维数组的值为权
        for(auto &t:times){
           /*  int x=times[0]-1,y=times[1]-1;
            g[x][y]=t[2]; */
        }
        vector<int> dist(n,inf);//记录最短路,初始化为最大值
        dist[k-1]=0;//出发节点
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            int x=-1;
            for(int y=0;y<n;y++){
                if(!vis[y] && (x==-1 || dist[y]<dist[x])){
                    x=y;
                }
            }
            vis[x]=true;//从当前节点x出发
            for(int y=0;y<n;y++){
                dist[y]=min(dist[y],dist[x]+g[x][y]);
            }
        }
        int ans=*max_element(dist.begin(),dist.end());
        return ans==inf?-1:ans;
    }
};
