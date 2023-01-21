// https://www.acmicpc.net/problem/1695

#include <iostream>

using namespace std;

int n, dp[5001][5001], s1[5001], s2[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i];
		s2[n - i + 1] = s1[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << n - dp[n][n];
}
