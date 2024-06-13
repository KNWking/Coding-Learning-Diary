#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

int n;
int A[N];

int main(){
    cin >> n;
    while(n--){
        memset(A, 0, sizeof(A));
        int num = 0; cin >> num;
        int ans = 0;
        for(int i = 2; i < num; ++i){
            if(num % i == 0){
                for(int j = i; j < num; j += i){
                    A[j] = 1;
                }
            }
        }
        for(int i = 1; i < num; ++i)
            if(!A[i]) ++ans;
        cout << ans << endl;
    }
    return 0;
}
