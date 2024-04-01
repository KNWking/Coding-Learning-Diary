#include <bits/stdc++.h>
using namespace std;

char c;
int n;  // 栈的写法就是把 n 换成栈。

int main(){
    while(true){
        c = getchar();
        if(c == '(') ++n;  // 换成入栈。
        else if(c == ')'){
            if(n != 0) --n;  // 换成出栈。
            else{ // 防止出现类似 “)(” 的情况。
                printf("NO\n");
                return 0;
            }
        }
        if(c == '@'){
            if(n == 0) printf("YES\n");
            else printf("NO\n");
            return 0;
        }
    }
}
