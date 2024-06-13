#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

list<int> lst1;
list<int> lst2;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int m = 0; cin >> m;
        lst1.push_back(m);
    }
    for(int i = 0; i < n; ++i){
        int m = 0; cin >> m;
        lst2.push_back(m);
    }
    lst1.merge(lst2);
    for(auto iter = lst1.begin(); iter != lst1.end(); ++iter)
        cout << *iter << (next(iter) == lst1.end() ? "\n" : " ");
    return 0;
}
