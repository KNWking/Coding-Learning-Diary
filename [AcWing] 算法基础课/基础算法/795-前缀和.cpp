#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 0; i < m; ++i) {
        int l = 0, r = 0;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
