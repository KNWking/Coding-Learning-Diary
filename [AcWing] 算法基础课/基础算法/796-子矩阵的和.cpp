#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m, q;
int a[N][N];

// 规定 S[0][0] == S[0][j] == s[i][0] == 0.
int S[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    // a[][] 的 i 和 j 都要从 1 开始。
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            // 计算前缀和。
            S[i][j] = S[i - 1][j] + S[i][j - 1]
                      - S[i - 1][j - 1] + a[i][j];
        }
    }

    /* 单独计算前缀和也可以。
     * for (int i = 1; i <= n; ++i) {
     *     for (int j = 1; j <= m; ++j) {
     *       S[i][j] = S[i - 1][j] + S[i][j - 1]
     *                 - S[i - 1][j - 1] + a[i][j];
     *     }
     * }
     */

    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 算子矩阵的和。
        int ans = S[x2][y2] - S[x2][y1 - 1]
                  - S[x1 - 1][y2] + S[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    return 0;
}
