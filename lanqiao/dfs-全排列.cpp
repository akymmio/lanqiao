#include <iostream>
#include <iomanip>
using namespace std;
int a[10];
bool vis[50];
int n;
void dfs(int step){
    if(step==n+1){
        for (int i = 1; i <= n;i++) {
            cout <<setw(5)<<a[i];
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n;i++) {
        if(vis[i]==0){
            vis[i] = 1;
            a[step] = i;
            dfs(step+1);
            vis[i] = 0;
        }
    }
    return;
}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}