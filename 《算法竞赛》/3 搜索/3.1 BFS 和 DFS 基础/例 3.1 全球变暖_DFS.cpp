#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char mp[N][N];  // 地图。
int vis[N][N] = {0};  // 标记是否搜索过。
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// 4 个方向。
int flag;  // 标记这个岛是否被完全淹没。

void dfs(int x, int y){
    vis[x][y] = 1;
    // 标记这个 # 被搜索过。
    if(mp[x][y + 1] == '#' && mp[x][y - 1] == '#'
       && mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        flag = 1; // 上下左右都是陆地，这是一个高地。
    for(int i = 0; i < 4; ++i){
        int nx = x + d[i][0], ny = y + d[i][1];
        if(vis[nx][ny] == 0 && mp[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> mp[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            if(mp[i][j] == '#' && vis[i][j] == 0){
                flag = 0;
                dfs(i, j);
                if(flag == 0) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
