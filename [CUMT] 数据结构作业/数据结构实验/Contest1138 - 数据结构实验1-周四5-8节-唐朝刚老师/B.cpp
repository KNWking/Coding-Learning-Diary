#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    while(cin >> n && n != 0){
        if(n == 0) break;
        int ans = n;
        for(int i = 2; i * i <= n; ++i){
            if(n % i == 0)
                ans = ans / i * (i - 1);
            while(n % i == 0){
                n /= i;
            }
        }
        if(n > 1)
            ans = ans / n * (n - 1);
        cout << ans << endl;
    }
    return 0;
}
