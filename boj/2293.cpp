// https://www.acmicpc.net/problem/2293

#include <iostream>

using namespace std;

int n, k, arr[102], dp[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	for (int i = 1; i <= n; i++) 
		for (int j = arr[i]; j <= k; j++) 
			dp[j] += dp[j - arr[i]];

	cout << dp[k];
}
