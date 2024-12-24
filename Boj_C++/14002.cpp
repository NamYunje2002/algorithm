// https://www.acmicpc.net/problem/14002

#include <iostream>

using namespace std;

int n, l, length, arr[1002], dp[1002], ans[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;

		for (int j = 0; j < i; j++) 
			if (arr[i] > arr[j]) 
				dp[i] = max(dp[i], dp[j] + 1);

		length = max(dp[i], length);
	}
	cout << length << "\n";
	l = length;

	// 수열 탐색
	for (int i = n - 1; i > -1; i--) 
		if (dp[i] == length)
			ans[--length] = arr[i];

	for (int i = 0; i < l; i++) cout << ans[i] << " ";
}
