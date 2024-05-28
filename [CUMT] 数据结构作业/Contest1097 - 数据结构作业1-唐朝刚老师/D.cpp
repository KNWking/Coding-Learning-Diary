#include <bits/stdc++.h>
using namespace std;

list<int> l;

int main() {
    ios::sync_with_stdio(false);
    int tmp = 0;
    while(cin >> tmp){
        l.push_back(tmp);
    }
    int maxv = l.front();
    int ans = 0;
    for(auto iter = l.begin(); iter != l.end(); ++iter){
        if(*iter > maxv){
            maxv = *iter;
            ans = 1;
        }else if(*iter == maxv){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
