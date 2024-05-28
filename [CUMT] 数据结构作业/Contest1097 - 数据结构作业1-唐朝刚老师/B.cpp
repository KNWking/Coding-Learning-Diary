#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int pos, data;
        cin >> pos >> data;
        s.insert(s.begin() + pos - 1, data);  // 插入数据到指定位置
    }

    for (size_t i = 0; i < s.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << endl;

    return 0;
}
