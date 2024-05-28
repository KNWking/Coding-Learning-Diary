#include <bits/stdc++.h>
using namespace std;

const int N= 1e4 + 10;

list<int> s;

int main() {
    ios::sync_with_stdio(false);
    int n = 0; cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp = 0; cin >> tmp;
        s.push_back(tmp);
    }

    int k = 0; cin >> k;
    for(int i = 0; i < k; ++i){
        int pos = 0, data = 0; cin >> pos >> data;
        auto iter = s.begin();
        advance(iter, pos - 1);
        s.insert(iter, data);
    }
    for(auto iter = s.begin(); iter != s.end(); ++iter){
        if(next(iter) != s.end())
            cout << *iter << " ";
        else
            cout << *iter;
    }
    cout << endl;
    return 0;
}
