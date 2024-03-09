// https://www.acmicpc.net/problem/11726

#include <iostream>

using namespace std;

int n, dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	cout << dp[n];
}
