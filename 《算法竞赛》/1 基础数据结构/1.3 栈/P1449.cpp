#include <bits/stdc++.h>
using namespace std;

stack<int> num;
int s, r, l;
char c;

/*
后缀表达式（逆波兰表达式）计算方法：
1. 开一个栈。
2. 从左至右扫描表达式。
3. 遇到数字时，将其压入栈。
4. 遇到运算符时，从堆栈中弹出所需数量的操作数（对于二元运算符是两个，对于一元运算符是一个），执行运算。
5. 将运算结果压入堆栈。
6. 重复步骤 3 到 4，直到表达式末尾。
7. 表达式结束后，堆栈顶的数字就是表达式的结果。
这里有一个注意点：对于二元运算符，如果这个运算符不满足交换律（如 '-'、'/'），
那么在逆波兰表达式中，左右操作数的位置不变，这样到了栈中就转换为了栈上部的数字为右操作数，
栈下部的数字为左操作数。如：a-b (中缀) => ab- (后缀) => ba (栈中，a 先入栈，b 后入栈)。
*/

int main(){
    while(true){
        c = getchar();
        while(c >= '0' && c <= '9'){
            // 只有非负数，无需考虑变号。
            s = s * 10 + (c - '0');
            c = getchar();
        }
        if(c == '.'){
            // 此 if 判断可以归入 switch 语句，
            // 为了方便理解单独拿出来判断。
            num.push(s);
            s = 0;  // 别忘了归零。
        }else{
            switch(c){
                case '+':
                    r = num.top();
                    num.pop();
                    l = num.top();
                    num.pop();
                    num.push(l + r);
                    break;
                case '*':
                    r = num.top();
                    num.pop();
                    l = num.top();
                    num.pop();
                    num.push(l * r);
                    break;
                case '-':
                    r = num.top();
                    num.pop();
                    l = num.top();
                    num.pop();
                    num.push(l - r);
                    break;
                case '/':
                    r = num.top();
                    num.pop();
                    l = num.top();
                    num.pop();
                    num.push(l / r);
                    break;
                case '@':
                    printf("%d\n", num.top());
                    return 0;
                    // 不建议用 goto 语句。
            }
        }
    }
}
