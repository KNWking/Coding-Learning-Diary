#include <bits/stdc+.h>
using namespace std;

inline int read()
{
    int s = 0, w = 1; // s数值，w符号
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}

int main(){
	read();
}
