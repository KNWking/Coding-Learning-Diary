#include <bits/stdc++.h>
using namespace std;

stack<char> s;
int n;
char c;

int main(){
    scanf("%d", &n);
    getchar();  // 捕捉第一行数字后的 '\n'.
    while(scanf("%c", &c) != EOF){
        if(c == '\n' || c == ' '){
            while(!s.empty()){  // 清空栈。
                printf("%c", s.top());
                s.pop();
            }
            putchar(c);
        }else s.push(c);
    }
    printf("\n");
    return 0;
}
