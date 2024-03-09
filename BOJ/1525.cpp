#include <iostream>
#include <queue>
#include <set>
using namespace std;

#define X first
#define Y second

int n, st, ans = -1;
int p10[10], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> Q;
set<int> vis;

// 다음 숫자(바꾸려는 숫자) 찾기
int getNxtNum(int num, int nxtIdx) {
	for (int i = 8; i > nxtIdx; i--) {
		num /= 10;
	}
	return num % 10;
}

// 0이 몇 번째 자리에 있는지 구하기
int getZeroIdx(int num) {
	int idx = 9;
	while (idx--) {
		if (num % 10 == 0) break;
		num /= 10;
	}
	return idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 거듭제곱 계산
	p10[0] = 1;
	for (int i = 1; i < 9; i++) p10[i] = p10[i - 1] * 10;

	for (int i = 8; i >= 0; i--) {
		cin >> n;
		st += n * p10[i];
	}
	Q.push({ st,0 });
	vis.insert(st);
	while (!Q.empty()) {
		int cur = Q.front().X;
		int cnt = Q.front().Y;
		Q.pop();

		// 정리되었을 경우
		if (cur == 123456780 && (ans == -1 || cnt < ans))
			ans = cnt;

		int zeroIdx = getZeroIdx(cur);
		int x = zeroIdx / 3;
		int y = zeroIdx % 3;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nxt = 0;
			int tmp = cur;
			
			if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;

			int nxtIdx = nx * 3 + ny;
			int nxtNum = getNxtNum(cur, nxtIdx);

			// 0이랑 다음 숫자(바꾸려는 숫자)랑 자리 바꾸기
			for (int j = 0; j < 9; j++) {
				int lastNum = tmp % 10;
				if (lastNum == 0) 
					nxt += lastNum * p10[8 - nxtIdx];
				else if (lastNum == nxtNum) 
					nxt += lastNum * p10[8 - zeroIdx];
				else 
					nxt += lastNum * p10[j];
				tmp /= 10;
			}
			if (vis.find(nxt) != vis.end()) continue;

			vis.insert(nxt);
			Q.push({ nxt, cnt + 1 });
		}
	}
	cout << ans;
}
