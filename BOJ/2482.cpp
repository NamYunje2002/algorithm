// https://www.acmicpc.net/source/53731724
/*

    - 테이블 정의
    dp[n][k] → n색상환에서 k개의 색을 고르는 경우의 수

    - 참고사항
    n색상환에서 하나의 색을 고르는 경우의 수 → 1
    k가 n/2보다 커질 때의 경우의 수 (k > n/2) → 0

*/

#include <iostream>

using namespace std;

int n, k, dp[1002][1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) dp[i][1] = i;

	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			if (j > i / 2) break;   
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
		}
	}
	cout << dp[n][k];
}
