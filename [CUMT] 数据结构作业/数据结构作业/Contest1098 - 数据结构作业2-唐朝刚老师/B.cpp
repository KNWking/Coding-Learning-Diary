#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    for(int t = 0; t < n; ++t){
        int tmp = 0; cin >> tmp;
        for(int i = 1; i <= tmp; ++i){
            for(int j = 1; j <= tmp; ++j)
                cout << i * j << (j != tmp? " " : "");
            cout << endl;
        }
    }
}
