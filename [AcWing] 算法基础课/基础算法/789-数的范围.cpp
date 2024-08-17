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
            cout << "-1 -1\n";
        } else {
            cout << l << " ";
            l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (num[mid] <= k) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            cout << r << endl;
        }
    }
    return 0;
}
