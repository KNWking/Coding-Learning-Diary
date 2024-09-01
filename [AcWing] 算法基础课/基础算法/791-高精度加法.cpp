#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;  // 进位。
    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10); // 个位。
        t /= 10;  // 确定进位。
    }
    if (t) C.push_back(t);
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
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; --i) {
        printf("%d", C[i]);
    }
    printf("\n");
    return 0;
}
