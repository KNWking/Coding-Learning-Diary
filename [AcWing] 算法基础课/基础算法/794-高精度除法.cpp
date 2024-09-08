#include <bits/stdc++.h>

using namespace std;

// A / b，商是 C，余数是 r，r 是引用。
vector<int> div(vector<int> &A, int &b, int &r) {
    vector<int> C;
    for (int i = A.size() - 1; i >= 0; --i) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    // 因为除法运算先得到的是高位，所以要 reverse.
    reverse(C.begin(), C.end());  // !!!
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
    int remainder = 0;  // 余数。
    auto C = div(A, b, remainder);
    for (int i = C.size() - 1; i >= 0; --i) {
        printf("%d", C[i]);
    }
    printf("\n");
    printf("%d\n", remainder);
    return 0;
}
