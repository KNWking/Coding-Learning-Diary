#include <bits/stdc++.h>
using namespace std;

vector<char> ans;
int n;
int r;
const char c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main() {
    cin >> n >> r;
    while(n > 0){
        ans.push_back(c[n % r]);
        n /= r;
    }
    if(ans.empty())
        ans.push_back('0');
    for(auto iter = prev(ans.end()); iter != ans.begin(); --iter)
        cout << *iter;
    cout << ans.front() << endl;
    return 0;
}
