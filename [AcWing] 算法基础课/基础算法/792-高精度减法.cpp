#include <bits/stdc++.h>

using namespace std;

// 如果 A >= B 则返回 true，否则为 false.
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() > B.size()) return true;
    if (A.size() < B.size()) return false;
    // A.size() == B.size()
    for (int i = A.size() - 1; i >= 0; --i) {
        // !!! 从最高位开始比较 !!!
        if (A[i] > B[i]) return true;
        if (A[i] < B[i]) return false;
    }
    return true;  // A == B.
}

// 提前通过附加的 cmp() 函数保证 A >= B.
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;  // 进位。

    // 已确定 A >= B, 所以 A.size() >= B.size().
    for (int i = 0; i < A.size(); ++i) {
        // 要先确定 B[i] 有没有越界。
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        if (t >= 0) {  // !!! 这里不是 t > 0 !!!
            C.push_back(t);
            t = 0;
            // !!! 不只是 t < 0 时要重置进位 !!!
        } else {
            C.push_back(t + 10);
            t = 1;
        }
    }
    // 去掉多余的前导零。
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string str1, str2;
    vector<int> A, B;
    cin >> str1 >> str2;
    for (int i = str1.size() - 1; i >= 0; --i) {
        A.push_back(str1[i] - '0');
    }
    for (int i = str2.size() - 1; i >= 0; --i) {
        B.push_back(str2[i] - '0');
    }
    if (cmp(A, B)) {  // !!! 要通过 cmp() 函数进行比较 !!!
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; --i) {
            printf("%d", C[i]);
        }
    } else {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; --i) {
            printf("%d", C[i]);
        }
    }
    printf("\n");
    return 0;
}
