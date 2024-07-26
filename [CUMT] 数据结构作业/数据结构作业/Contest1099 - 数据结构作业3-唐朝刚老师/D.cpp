#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main(){
    int n = 0; cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp = 0; cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for(auto iter = vec.begin(); iter != vec.end(); ++iter)
        cout << *iter << (next(iter) == vec.end() ? "\n" : " ");
    return 0;
}
