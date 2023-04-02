#include <iostream>
using namespace std;
int map[100][100];
int map2[100][100];
int n,m;
const int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{-1,1},{-1,-1},{1,-1},{1,1}};
void dfs(int x,int y){   
    if(map[x][y]){
        map2[x][y] = 9;
        return;
    }        
    int count = 0;//À×µÄÊıÁ¿
    for (int i = 0; i < 8;i++) {    

        int dx = x + dir[i][0], dy = y + dir[i][1];
        if(dx>0 && dx<=m && dy>0 && dy<=n){
            if(map[dx][dy]==1){
                count++;
            }        
        }
        
    }map2[x][y]=count;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m;j++) {
            cin >> map[i][j];
               
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++) {
            dfs(i,j);
            cout<< map2[i][j]<<" ";
            if(j==4){
                cout << "\n";
            }
        }
    }
}