#include <bits/stdc++.h>
using namespace std;

int Find(int x, vector<int>& p) {
	if (x == p[x]) return x;
	return p[x] = Find(p[x], p);
}

void Union(int x, int y, vector<int>& p) {
	x = Find(x, p);
	y = Find(y, p);
	p[x] = y;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> p(n + 1);
	for (int i = 0; i <= n; i++) p[i] = i;
	while (m--) {
		int o, a, b;
		cin >> o >> a >> b;
		if (o == 0) Union(a, b, p);
		else cout << (Find(a, p) == Find(b, p) ? "YES" : "NO") << "\n";
	}
}