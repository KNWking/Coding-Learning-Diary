#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	while (n--) {
		vector<int> vec;
		int m = 0;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int tmp = 0;
			cin >> tmp;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end());
		int min = vec[0];
		bool found = false;
		auto iter = vec.begin();
		for (; iter != vec.end(); ++iter) {
			if (*iter > min) {
				cout << (int)*iter << endl;
				found = true;
				break;
			}
		}
		if (!found)
			cout << "NO" << endl;
	}
	return 0;
}
