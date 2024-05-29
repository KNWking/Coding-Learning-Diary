#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;
bool no1 = false, no2 = false, no3 = false;

int main() {
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        char c = str[i];
        // 只记录括号。
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                // 栈为空且有闭合括号，记录不匹配类型。
                if (c == ')') no1 = true;
                else if (c == ']') no2 = true;
                else if (c == '}') no3 = true;
            } else {
                char top = s.top();
                if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) {
                    s.pop();
                } else {
                    // 不匹配，记录不匹配类型。
                    if (c == ')') no1 = true;
                    else if (c == ']') no2 = true;
                    else if (c == '}') no3 = true;
                }
            }
        }
    }
    // 如果栈不为空，记录未匹配的括号类型。
    while (!s.empty()) {
        char top = s.top();
        s.pop();
        if (top == '(') no1 = true;
        else if (top == '[') no2 = true;
        else if (top == '{') no3 = true;
    }
    // 根据优先级输出结果
    if (no1) cout << "NO1\n";
    else if (no2) cout << "NO2\n";
    else if (no3) cout << "NO3\n";
    else cout << "YES\n";  // 所有括号正确匹配。
    return 0;
}
