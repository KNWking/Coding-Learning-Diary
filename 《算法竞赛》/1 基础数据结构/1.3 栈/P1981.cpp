#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e4;
stack<int> s;
char c;
int num;

int main(){
    scanf("%d", &num);
    s.push(num);
    while(scanf("%c", &c) != EOF && c != '\n'){
        // while(scanf("%c", &c) != EOF) 无法通过。
        scanf("%d", &num);
        num %= MOD; // 时刻记得要取模。
        if(c == '*'){
            // '*' 优先级高，先计算。
            num *= s.top();
            num %= MOD;
            s.pop();
        }
        s.push(num);
    }
    num = 0;
    while(!s.empty()){
        // 最后把栈中数字一一相加。
        num += s.top();
        num %= MOD;
        s.pop();
    }
    printf("%d\n", num);
    return 0;
}
