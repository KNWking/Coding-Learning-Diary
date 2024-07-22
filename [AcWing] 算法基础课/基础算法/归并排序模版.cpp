#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int q[N], tmp[N];
int n;

void mergeSort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    // 1. 确定 mid.

    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    // 2. 递归。

    int k = 0; // 说明当前 tmp 里有多少元素，也是 index.
    int i = l, j = mid + 1;
    // 两边的起点。
    while (i <= mid && j <= r) {
        // 3. 二路归并。
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }

    for (i = l, j = 0; i <= r; ++i, ++j) {
        q[i] = tmp[j];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    mergeSort(q, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", q[i]);
    }
    return 0;
}
