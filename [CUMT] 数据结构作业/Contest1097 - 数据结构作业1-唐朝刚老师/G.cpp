#include <bits/stdc++.h>

using namespace std;

stack<char> s;
vector<char> ans;

bool compare(char a, char b) {
    // a 高于 b 则返回 true，否则 (a 低于或等于 b) 返回 false.
    if (a == '*' && b == '+') return true;
    if (a == '*' && b == '-') return true;
    if (a == '/' && b == '+') return true;
    if (a == '/' && b == '-') return true;
    else return false;
}

int main() {
    char c = 0;
    int ope_n = 0;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            ans.push_back(c);
            while ((c = getchar()) != EOF && isdigit(c))
                ans.push_back(c);
            ans.push_back(' ');
            if (c == EOF) break;
        }
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (true) {
                char tmp = s.top();
                if (tmp == '(') {
                    s.pop();
                    break;
                } else {
                    ans.push_back(tmp);
                    ans.push_back(' ');
                    s.pop();
                }
            }
        } else {
            while (!s.empty() && !compare(c, s.top()) && s.top() != '(') {
                ans.push_back(s.top());
                ans.push_back(' ');
                s.pop();
                ope_n--;
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        ans.push_back(s.top());
        ans.push_back(' ');
        s.pop();
    }
    for (auto iter = ans.begin(); next(iter) != ans.end(); ++iter)
        cout << *iter;
    cout << endl;
    return 0;
}
