#include <bits/stdc++.h>
using namespace std;

string s;
int ans;
// 中心扩展法。
void check(int lpos, int rpos) {
    while (lpos >= 0 && rpos < s.size()
           && s[lpos] == s[rpos]) {
        ++ans;  // 每找到一个回文串，计数加一。
        --lpos;  // 向左扩展。
        ++rpos;  // 向右扩展。
    }
}

int main() {
    while (cin >> s) {
        ans = 0;  // 初始化回文子串计数
        for (int i = 0; i < s.size(); ++i) {
            check(i, i);
            // 奇数长度的回文串。
            if (i + 1 < s.size()) {
                // 防 i + 1 越界。
                check(i, i + 1);
                // 偶数长度的回文串。
            }
        }
        cout << ans << endl;
    }
    return 0;
}
