#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
string s;

int main() {
    while (getline(cin, s) && s != "END") {
        sort(s.begin(), s.end());
        int num = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                pq.push(num);
                num = 1;  // 一种字符出现的次数。
            } else {
                num++;
            }
        }
        pq.push(num); // 确保将最后一个字符的频率推入队列。
        // 与原书中不同，防止数组越界。
        int ans = 0;  // huffman 编码长度。
        if (pq.size() == 1) {  // 题目的一个坑：只有一种字符的情况。
            ans = s.size();
        } else {
            while (pq.size() > 1) {  // 最后一次合并不用加到 ans 中。
                int a = pq.top();  // 贪心：取出频次最少的两个。
                pq.pop();
                int b = pq.top();
                pq.pop();
                pq.push(a + b);
                ans += a + b;  // 一种字符进几次队列，就累加几次。
                // 进一次队列，表示它在二叉树上深了一层，编码长度加 1。
            }
        }
        pq.pop(); // 清空最后一个元素。
        printf("%d %d %.1f\n", s.size() * 8, ans, (double) s.size() * 8 / (double) ans);
    }
    return 0;
}
