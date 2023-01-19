// https://www.acmicpc.net/problem/9252

#include <iostream>

using namespace std;

int l, dp[1002][1002];
char ans[1002];
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
	l = dp[s2.size()][s1.size()];
	cout << l << "\n";
	for (int i = s2.size(); i > 0; i--) {
		for (int j = s1.size(); j > 0; j--) {
			if (s1[j - 1] == s2[i - 1] && l == dp[i][j]) {
				ans[--l] = s1[j - 1];
				break;
			}
		}
	}
	for (int i = 0; i < dp[s2.size()][s1.size()]; i++)
		cout << ans[i];
}
