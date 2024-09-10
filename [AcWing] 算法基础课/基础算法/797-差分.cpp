#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;


int n, m;
// and[0] = 0.
int a[N], b[N], ans[N];

inline void insert(int l, int r, int c) {
    b[l] += c;
    // 这里最好换成 vector，然后判断
    // if (r + 1 < b.size()) 防止数组越界。
    b[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    // 构造差分数组 b[].
    for (int i = 1; i <= n; ++i) {
        insert(i, i, a[i]);
    }

    /* 也可以通过差分的定义来获得 b[i].
     * for (int i = 1; i <=n; ++i) {
     *     b[i] = a[i] - a[i - 1];
     * }
     */

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i - 1] + b[i];
    }
    // 输出可以合并到上面的 for 循环中。
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
