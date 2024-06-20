#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int main(){
    int n = 0; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int tmp = 0; cin >> tmp;
			// 根据题意，不需要开一个数组存储，
			// 直接相加对角线上的数字即可。
            if(i == j){
                ans += tmp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
