#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
list<int> lst;
list<int>::iterator iter[N];
bool exist[N];
int main () {
    int n = 0; scanf("%d", &n);
    lst.push_back(1);
    iter[1] = lst.begin();
    exist[1] = true;

    for(int i = 2; i <= n; ++i){
        exist[i] = true;
        int k = 0, p = 0; scanf("%d%d", &k, &p);
        if(p == 0){
            iter[i] = lst.insert(iter[k], i);
        }else{
            iter[i] = lst.insert(next(iter[k]), i);
        }
    }

    int k = 0, p = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i){
        scanf("%d", &p);
        if(exist[p]) lst.erase(iter[p]);
        exist[p] = false;
    }

    for(auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << (next(it) == lst.end() ? '\n' : ' ');
    /*
     * cout << *it << (next(it) == lst.end()) ? '\n' : ' ';
     * 是错误的，因为 << 优先级比三元运算符 ?: 高，所以应该用括号包裹 ?: 运算符。
    */
    return 0;
}
