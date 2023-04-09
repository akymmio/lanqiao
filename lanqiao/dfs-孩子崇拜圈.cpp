#include <iostream>
using namespace std;
const int N=1e5+10;
int ans;
int a[N];
bool vis[N];
void dfs(int n,int step,int i){ //i为起点
    if (vis[n] && n!=i) {
        return;//构不成圈子
    }
    if(vis[n] && n==i){
        ans = max(ans,step);
        return;
    }
    vis[n] = true;
    dfs(a[n],step+1,i);
    vis[n] = false;
    return;
}
int main(){
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i = 1;i<=n;i++) {
        vis[i] = true;
        dfs(a[i],1,i);
    }
    cout << ans;
    return 0;
}