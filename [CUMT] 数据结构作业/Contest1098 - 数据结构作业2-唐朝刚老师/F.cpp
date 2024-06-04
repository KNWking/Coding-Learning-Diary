#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;

int d[4][2] = {{0, 1},{0, -1},
               {1, 0}, {-1, 0}};
int t, n, m;
int sx, sy, ex, ey;
char mp[N][N];
bool vis[N][N];

bool isValid(int x, int y) {
    // 判断是否到边界。
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs();

int main(){
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> m;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
                cin >> mp[j][k];
                if(mp[j][k] == 'S'){
                    sx = j;
                    sy = k;
                }else if(mp[j][k] == 'E'){
                    ex = j;
                    ey = k;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        // 因为有多组数据，所以每次 bfs 完要重置 vis.
        int ans = bfs();
        cout << ans << endl;
    }
    return 0;
}

int bfs(){
    queue<tuple<int, int, int>> q; // x, y, distance.
    q.push({sx, sy, 0});
    vis[sx][sy] = true;
    while(!q.empty()){
        auto [x, y, dis] = q.front();
        q.pop();
        if(x == ex && y == ey)
            return dis;
        for(int i = 0; i < 4; ++i){
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(isValid(nx, ny) && !vis[nx][ny] && mp[nx][ny] != '#'){
                q.push({nx, ny, dis + 1});
                vis[nx][ny] = true;
            }
        }
    }
    return -1;
}
