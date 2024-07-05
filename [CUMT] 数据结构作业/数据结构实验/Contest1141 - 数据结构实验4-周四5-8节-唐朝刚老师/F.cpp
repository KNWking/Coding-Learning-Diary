#include <bits/stdc++.h>
using namespace std;

vector<int> vec1;
vector<int> vec2;

int main() {
	for (int i = 0; i < 10; ++i) {
		int x = 0;
		cin >> x;
		if (x % 2 == 0)
			vec2.push_back(x);
		else
			vec1.push_back(x);
	}
	sort(vec1.begin(), vec1.end(), greater<int>());
	sort(vec2.begin(), vec2.end());
	for (auto d : vec1)
		cout << d << " ";
	for (auto d : vec2)
		cout << d << " ";
	cout << endl;
	return 0;
}
