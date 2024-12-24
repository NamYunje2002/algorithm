// https://www.acmicpc.net/problem/9251 

#include <iostream>

using namespace std;

int dp[1002][1002];
string s1, s2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2;

	for (int i = 0; i < s2.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if (s1[j] == s2[i]) 
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else 
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	cout << dp[s2.size()][s1.size()];
}
