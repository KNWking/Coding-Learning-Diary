#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int num[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    while (m--) {
        int k = 0;
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (num[mid] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (num[l] != k) {
            printf("-1 -1\n");
        } else {
            printf("%d ", l);
            int l2 = 0, r2 = n - 1;
            while (l2 < r2) {
                int mid2 = (l2 + r2 + 1) >> 1;
                if (num[mid2] <= k) {
                    l2 = mid2;
                } else {
                    r2 = mid2 - 1;
                }
            }
            printf("%d\n", l2);
        }
    }
    return 0;
}
