#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> vec;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else
		return p1.first > p2.first;
}

int main() {
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		int tmp = x;
		int sum = 0;
		while (tmp / 10 != 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		sum += tmp;
		vec.push_back({x, sum});
	}
	sort(vec.begin(), vec.end(), compare);
	for (auto p : vec) {
		cout << p.first << " ";
	}
	cout << endl;
	return 0;
}
