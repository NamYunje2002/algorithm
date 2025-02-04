#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	if (n == 1) {
		cout << "A";
	}
	else if (n == 2) {
		if (v[0] == v[1]) cout << v[0];
		else cout << "A";
	}
	else {
		string ans = "B";
		for (int a = -200; a <= 200; a++) {
			int flag = 1, b = v[1] - v[0] * a;
			for (int k = 1; k < n; k++) {
				if (v[k - 1] * a + b != v[k]) flag = 0;
			}
			if (flag) ans = to_string(v[n - 1] * a + b);
		}
		cout << ans;
	}
}