#include <bits/stdc++.h>
using namespace std;

string s;
int ans;
// 中心扩展法。
void check(int posl, int posr) {
    while (posl >= 0 && posr < s.size() && s[posl] == s[posr]) {
        ++ans;
        --posl;
        ++posr;
    }
}

int main() {
    while (cin >> s) {
        ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            check(i, i);
            if (i + 1 < s.size()) {
                check(i, i + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
