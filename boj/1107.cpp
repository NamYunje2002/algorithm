/* https://www.acmicpc.net/problem/1107 */

#include <iostream>

using namespace std;

int n, m, k, ans, btn[12];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> k;
		btn[k] = 1;
	}
  
	// 지금 보고 있는 채널(100번)에서 +버튼 또는 -버튼 사용
	ans = abs(n - 100);

	// 0번 채널로 이동 후, +버튼 사용
	if (!btn[0]) 
		ans = min(ans, n + 1);
	
	//  i번째 채널로 이동 후, +버튼 또는 -버튼 사용
	for (int i = 1; i < 1000001; i++) {
		int t = i, isBroken = 0, cnt = 0;
		while (t > 0) {
			if (btn[t % 10]) {
				isBroken = 1;
				break;
			}
			t /= 10;
			cnt++;
		}
		if (isBroken) continue;
		cnt += abs(n - i);
		ans = min(ans, cnt);
	}
	cout << ans;
}
