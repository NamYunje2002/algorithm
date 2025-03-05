#include <bits/stdc++.h>
using namespace std;

int dp[31];

int main() {
	int n; cin >> n;
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] += dp[2] * dp[i - 2];
		for (int j = i - 2; j >= 4; j -= 2) {
			dp[i] += 2 * dp[i - j];
		}
		dp[i] += 2;
	}
	cout << dp[n];
}