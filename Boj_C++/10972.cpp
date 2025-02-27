#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n), ans(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int a = -1;
	for (int i = n - 1; i > 0; i--) {
		if (v[i] > v[i - 1]) {
			a = i - 1;
			break;
		}
	}
	if (a == -1) {
		cout << -1;
	} else {
		int b = a + 1;
		for (int i = a + 2; i < n; i++) {
			if (v[a] < v[i] && v[i] < v[b]) b = i;
		}
		int tmp = v[a];
		v[a] = v[b];
		v[b] = tmp;
		sort(v.begin() + a + 1, v.end());
		for (int i = 0; i < n; i++) cout << v[i] << ' ';
	}
}