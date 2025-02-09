#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, b; cin >> n >> b;
	string ans = "";
	while (n) {
		if (n % b > 9) ans += (char)(n % b - 10 + 'A');
		else ans += to_string(n % b);
		n /= b;
	}
	for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i];
}