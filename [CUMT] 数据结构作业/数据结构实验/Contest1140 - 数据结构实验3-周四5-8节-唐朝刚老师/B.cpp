#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    while(cin >> n){
        priority_queue<int, vector<int>, greater<int>> pq;
		// 因为只要求权值，所以不用算每个的编码。
        for(int i = 0; i < n; ++i){
            int tmp = 0; cin >> tmp;
            pq.push(tmp);
        }
        int ans = 0;
        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << endl;
    }

    return 0;
}
