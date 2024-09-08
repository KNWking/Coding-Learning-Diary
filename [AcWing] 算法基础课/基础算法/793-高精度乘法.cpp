#include <bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, int &b) {
    vector<int> C;
    int t = 0;  // 进位。

    // 这里并上 t 是为了处理乘法结束后的进位。
    for (int i = 0; i < A.size() || t; ++i) {
        if (i < A.size()) t += A[i] * b;
        // 下面类似高精度加法。
        C.push_back(t % 10);
        t /= 10;
    }
    // 去除前导 0。
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) {
        A.push_back(a[i] - '0');
    }
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; --i) {
        printf("%d", C[i]);
    }
    printf("\n");
    return 0;
}
