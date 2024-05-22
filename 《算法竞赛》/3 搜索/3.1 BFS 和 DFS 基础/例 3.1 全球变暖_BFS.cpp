#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

// 与 DFS 方案类似的部分不再赘述。
char mp[N][N];
int vis[N][N];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int flag;

void bfs(int x, int y){
    // 类比二叉树的 BFS 搜索方法。
    vis[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        int tx = tmp.first;
        int ty = tmp.second;
        if(mp[tx][ty + 1] == '#' && mp[tx][ty - 1] == '#'
        && mp[tx + 1][ty] == '#' && mp[tx - 1][ty] == '#')
            flag = 1;
        for(int i = 0; i < 4; ++i){
            int nx = tx + d[i][0];
            int ny = ty + d[i][1];
            if(mp[nx][ny] == '#' && vis[nx][ny] == 0){
                // if 中条件作用为判断连通性。
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int n, ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> mp[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < n; ++j){  // 类似 DFS 方案的部分。
            if(mp[i][j] == '#' && vis[i][j] == 0){
                flag = 0;
                bfs(i, j);
                if(flag == 0) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
