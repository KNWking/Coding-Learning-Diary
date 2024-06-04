#include <bits/stdc++.h>
using namespace std;

const double esp = 1e-5;
// 这里给 1e-6 会出错。

int a[10];
int ans[10];

void lin();
void qs();
void fib();
bool islin(){
    int d = a[1] - a[0];
    for(int i = 2; i < 5; ++i){
        if(a[i] - a[i - 1] != d) return false;
    }
    return true;
}
bool isq(){
    for(int i = 0; i < 5; ++i)
        if(a[i] == 0) return false;
    double q = (double) a[1] / a[0];
    for(int i = 2; i < 5; ++i){
        if(fabs(q - ((double) a[i] / a[i - 1])) > esp) return false;
    }
    return true;
}
// 筛两次后就不用判断 fib 数列了，美滋滋。

int main(){
    for(int i = 0; i < 5; ++i)
        cin >> a[i];
    while(!(a[0] == 0 && a[1] == 0 && a[2] == 0 &&
            a[3] == 0 && a[4] == 0)){
        if(islin()){
            lin();
        }else if(isq()){
            qs();
        }else{ // 不用再筛了。
            fib();
        }
        for(int i = 0; i < 4; ++i)
            cout << ans[i] << " ";
        cout << ans[4] << endl;
        for(int i = 0; i < 5; ++i)
            cin >> a[i];
    }
}

void lin(){
    int d = a[1] - a[0];
    for(int i = 0; i < 5; ++i){
        ans[i] = a[4] + (i + 1) * d;
    }
}
void qs(){
    double q = (double) a[1] / a[0];
    int tmp = a[4];
    for(int i = 0; i < 5; ++i){
        ans[i] = a[4] * pow(q, i + 1);
    }
}
void fib(){
    ans[0] = a[3] + a[4];
    ans[1] = a[4] + ans[0];
    for(int i = 2; i < 5; ++i){
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}
