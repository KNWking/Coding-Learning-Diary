#include <bits/stdc++.h>
using namespace std;

stack<double> sta;
vector<string> tokens;
string token;
string s;

bool isop(string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double calculate(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    else return 0;
}

void calPN();

int main() {
    getline(cin, s);
    calPN();
    return 0;
}

void calPN() {
    int start = 0, end = 0;
    while ((end = s.find(' ', start)) != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    reverse(tokens.begin(), tokens.end());
    for (auto iter = tokens.begin(); iter != tokens.end(); ++iter) {
        if (isop(*iter)) {
            double a = sta.top(); sta.pop();
            double b = sta.top(); sta.pop();
            double ans = calculate(a, b, *iter);
            sta.push(ans);
        } else {
            sta.push(stod(*iter));
        }
    }
    cout << fixed << setprecision(6) << sta.top() << endl;
}
