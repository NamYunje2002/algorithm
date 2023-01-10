// https://www.acmicpc.net/problem/2629
/*

	- 테이블 정의
	dp[idx][weight] → idx번 추까지 사용했을 때 weight(무게)확인이 가능한지에 대한 여부
	
	- 접근
	3가지 경우로 나눈 뒤 반복
	1. 추를 사용하지 않음 (weight)
	2. 추를 왼쪽(유리구슬이 올려져 있는 곳)에 올림 (weight + wArr[idx])
	3. 추를 오른쪽(유리구슬이 올려져 있지 않은 곳)에 올림 (abs(weight - wArr[idx]))

	- 참고사항
	주어진 유리구슬의 무게가 15,000 초과이면인확인 불가능 (추의 개수 <= 30, 추의 무게 <= 500) → N 출

*/

#include <iostream>

using namespace std;

int wCnt, mCnt, marble, wArr[32], dp[32][15002];

void func(int idx, int weight) {
	if (idx > wCnt || dp[idx][weight]) return;
	dp[idx][weight] = 1;
	func(idx + 1, weight);
	func(idx + 1, weight + wArr[idx]);
	func(idx + 1, abs(weight - wArr[idx]));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> wCnt;
	for (int i = 0; i < wCnt; i++) cin >> wArr[i];

	func(0, 0);

	cin >> mCnt;
	while (mCnt--) {
		cin >> marble;
		if (marble > 15000) cout << "N ";
		else if (dp[wCnt][marble]) cout << "Y ";
		else cout << "N ";
	}
}
