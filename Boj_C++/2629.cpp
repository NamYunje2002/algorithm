// https://www.acmicpc.net/problem/2629
/*

	- 테이블 정의
	dp[idx][weight] → idx번 추까지 사용했을 때 weight(무게)확인이 가능한지에 대한 여부
	
	- 접근
	3가지 경우로 나눈 뒤 반복
	1. 추를 사용하지 않음 (weight)
	2. 추를 왼쪽(유리구슬이 올려져 있는 곳)에 올림 (weight + c[idx])
	3. 추를 오른쪽(유리구슬이 올려져 있지 않은 곳)에 올림 (abs(weight - c[idx]))

	- 참고사항
	주어진 유리구슬의 무게가 15,000을 초과하면 확인 불가능 (추의 개수 <= 30, 추의 무게 <= 500) → N 출력

*/

#include <iostream>

using namespace std;

int n, wCnt, w, c[32], dp[32][15002];

void func(int idx, int weight) {
	if (idx > n || dp[idx][weight]) return;
	dp[idx][weight] = 1;
	func(idx + 1, weight);
	func(idx + 1, weight + c[idx]);
	func(idx + 1, abs(weight - c[idx]));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];

	func(0, 0);

	cin >> wCnt;
	while (wCnt--) {
		cin >> w;
		if (w > 15000) cout << "N ";
		else if (dp[n][w]) cout << "Y ";
		else cout << "N ";
	}
}
