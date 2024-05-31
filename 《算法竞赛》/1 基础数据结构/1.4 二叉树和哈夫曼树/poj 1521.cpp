#include <bits/stdc++.h>
using namespace std;

int main(){
	priority_queue <int, vector<int>, greater<int>> pq;
	// 新建一个最小堆。
	string s;
	while(getline(cin, s) && s != "END"){
		sort(s.begin(), s.end());
		int num = 1;      // 一种字符出现的次数。
	    for(int i = 1; i <= s.length(); i++){
			if(s[i] != s[i-1]){ q.push(num);  num = 1;}
	        else num++;
		}
		int ans = 0;
        if(q.size() == 1)  // 题目的一个坑：只有一种字符的情况。
        ans = s.length();
		while(q.size() > 1){  //最后一次合并不用加到 ans 中。		   
			int a = q.top(); q.pop();  //贪心：取出频次最少的两个。     
            int b = q.top(); q.pop();
            q.push(a+b);  //把两个最小的合并成新的结点，重新放进队列。
            ans += a+b;  //一种字符进几次队列，就累加几次。
            //进一次队列，表示它在二叉树上深了一层，编码长度加 1。
		}
		q.pop();
		printf("%d %d %.1f\n", s.length() * 8, ans, (double) s.length() * 8 / (double) ans);
	}
	return 0;
}
