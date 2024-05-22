#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char mp[N][N];  // 地图。
int vis[N][N] = {0};  // 标记是否搜索过。
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// 4 个方向。
int flag;
// 标记这个岛是否被完全淹没。0 是淹没，1 是高地。

void dfs(int x, int y){
    // 寻找该联通大陆有无高地。
    // 由于 mp[x][y] 是一陆地，
    // 因此 if 语句直接判断其四周是否是陆地。
    vis[x][y] = 1; // 标记这个 # 被搜索过。该代码处在的位置很重要！
    if(mp[x][y + 1] == '#' && mp[x][y - 1] == '#'
       && mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        flag = 1; // 上下左右都是陆地，这是一个高地。
    for(int i = 0; i < 4; ++i){
        int nx = x + d[i][0], ny = y + d[i][1];
        if(vis[nx][ny] == 0 && mp[nx][ny] == '#')
            // 别忘了这个 if 语句。考虑第一次使用 dfs() 函数时的情景。
            dfs(nx, ny);
        // 向四个方向递归搜索。原理联想二叉树的 dfs 搜索。
    }
    // 由题，dfs 函数无需检查边界，但其他题目不一定。
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> mp[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            // 搜索所有像素点。
            // i 和 j 都从 1 开始，因为边界都是水。
            if(mp[i][j] == '#' && vis[i][j] == 0){
                flag = 0; // 假设这个岛被淹没。
                dfs(i, j);
                // 寻找该联通大陆有无高地。
                if(flag == 0) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
