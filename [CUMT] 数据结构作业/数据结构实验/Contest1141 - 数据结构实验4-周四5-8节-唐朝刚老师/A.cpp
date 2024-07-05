#include <bits/stdc++.h>
using namespace std;

map<string, string> parent;
map<string, int> data;

int main() {
	int n;
	cin >> n;
	int numEdges = pow(2, n + 1) - 2;
	for (int i = 0; i < numEdges; ++i) {
		string m, n;
		int len;
		cin >> m >> n >> len;
		parent[n] = m;
		data[n] = len;
	}
	string p;
	cin >> p;
	int ans = 0;

	while (parent.count(p)) {
		ans += data[p];
		p = parent[p];
	}
	cout << ans << endl;
	return 0;
}
