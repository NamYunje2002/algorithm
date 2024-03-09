// https://www.acmicpc.net/problem/13458

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	long long ans = n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int b, c; cin >> b >> c;
	for (int i = 0; i < n; i++) {
		v[i] = max(0, v[i] - b);
		ans += v[i] / c;
		if (v[i] % c != 0) ans++;
	}
	cout << ans;
}
