#include <iostream>
#include <vector>
#include <algorithm> //max_element
#include <cstring> //memset
using namespace std;
const int N = 21, n = 19; // 19����ĸ
int dist[N];              // ��֪��������·
int g[N][N];              //��ǰ�ڵ�·������
bool vis[N];              //�ڵ���ʱ��
void add(int a, int b, int c) { g[a][b] = g[b][a] = c; } // ��ӱߺ�Ȩֵ

int diskt() {
    memset(dist, 0x3f, sizeof(dist)); // �൱�ڳ�ʼ�������
    dist[1] = 0;                      // ��㵽�ڵ�����·
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) {//
                t = j; 
            }
        }
        for (int j = 1; j < n; j++) {
            dist[j] = min(dist[j], dist[t] + g[i][j]); // ��㵽�ڵ�i�ľ���+�ڵ�i��j=��㵽j�ľ���
        }
        vis[t] = true;
    }
}


//leetcode�����ӳ�ʱ��
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf=INT_MAX/2;
        vector<vector<int>> g(n,vector<int>(n,inf));//x,y�±��ʾ�ߣ���Ӧ��ά�����ֵΪȨ
        for(auto &t:times){
           /*  int x=times[0]-1,y=times[1]-1;
            g[x][y]=t[2]; */
        }
        vector<int> dist(n,inf);//��¼���·,��ʼ��Ϊ���ֵ
        dist[k-1]=0;//�����ڵ�
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            int x=-1;
            for(int y=0;y<n;y++){
                if(!vis[y] && (x==-1 || dist[y]<dist[x])){
                    x=y;
                }
            }
            vis[x]=true;//�ӵ�ǰ�ڵ�x����
            for(int y=0;y<n;y++){
                dist[y]=min(dist[y],dist[x]+g[x][y]);
            }
        }
        int ans=*max_element(dist.begin(),dist.end());
        return ans==inf?-1:ans;
    }
};
