#include <bits/stdc++.h>
using namespace std;

int main(){
  // 类似书上例题，无需建树。
	int n = 0; cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		priority_queue<int, vector<int>, greater<int>> pq;
		int m = 0; cin >> m;
		int num = 1, ans = 0;
		cin >> s;
		sort(s.begin(), s.end());
		for(int i = 1; i < s.size(); ++i){
			if(s[i] != s[i - 1]){
				pq.push(num);
				num = 1;
			}else{
				++num;
			}
		}
		pq.push(num);  // 最后一个也要加入。
		if(pq.size() == 1){ans = s.size();}
		else{
			while(pq.size() > 1){
				int a = pq.top();
				pq.pop();
				int b = pq.top();
				pq.pop();
				pq.push(a + b);
				ans += a + b;
			}
			pq.pop();
		}
		if(ans <= m)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
   return 0;
}
