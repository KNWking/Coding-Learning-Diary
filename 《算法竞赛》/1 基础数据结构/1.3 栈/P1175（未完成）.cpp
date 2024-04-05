#include <bits/stdc++.h>
using namespace std;

const int N = 138;
stack<int> sn;
stack<char> sc;
vector<int> cal;
char c;
char tran[N];
int pos = 0, len, n;

bool compare(char c1, char c2);
// c1 优先级高于 c2，则返回 true，否则为 false。
void transfer();
// 最初的转换。
void calculate();
// 从后缀表达式开始计算。

int main(){
    transfer();
    len = pos;
    for(int i = 0; i < len - 1; ++i) printf("%c ", tran[i]);
    printf("%c\n", tran[len - 1]);
    calculate();
    return 0;
}

void transfer(){
    // 单独可以出个小题。
    while(scanf("%c", &c) != EOF && c != '\n'){
        if(c >= '0' && c <= '9') tran[pos++] = c;
        else if(c == '(') sc.push(c);
        else if(c == ')'){  // 遇到右括号 ')'
            while(sc.top() != '('){
                // 弹出并输出运算符，直到遇到左括号 '('
                tran[pos++] = sc.top();
                sc.pop();
            }
            sc.pop();  // 弹出左括号 '('
        } else{
            if(!sc.empty() && sc.top() == '('){
                // 注意要判定 !sc.empty()，
                // 因为 top() 函数在 stack 为空时无定义。
                sc.push(c);
                continue;
            }
            while(!sc.empty() && !compare(c, sc.top())){
                tran[pos++] = sc.top();
                sc.pop();
            }
            sc.push(c);
        }
    }
    while(!sc.empty()){
        tran[pos++] = sc.top();
        sc.pop();
    }
}

void calculate(){
    for(int i = 0; i < len; ++i){
        if(tran[i] > '9' || tran[i] < '0') ++n;
    }
    for(int i = 0; i < n; ++i){
    }
}


bool compare(char c1, char c2){
    // c1 优先级高于 c2，则返回 true，否则为 false。
    if((c1 == '^')  // 对 '^' 无多余判定，因为是从右向左结合，且在此优先级最高。
    || (c1 == '*' && c2 == '+')
    || (c1 == '*' && c2 == '-')
    || (c1 == '/' && c2 == '+')
    || (c1 == '/' && c2 == '-')) return true;
    else return false;
}
