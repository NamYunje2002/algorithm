#include <bits/stdc++.h>
using namespace std;

int n, ans = -1, ansCnt;
int mArr[4], sArr[16][5], cArr[16], ansArr[16];

void solve(int idx, int k, int cCnt, int tCnt) {
	if (cCnt == tCnt) {
		int ret[5] = { 0,0,0,0,0 };
		for (int i = 0; i < cCnt; i++) {
			for (int j = 0; j < 5; j++) {
				ret[j] += sArr[cArr[i]][j];
			}
		}
		int chk = 1;
		for (int i = 0; i < 4; i++) {
			if (ret[i] < mArr[i]) chk = 0;
		}
		if (chk) {
			if (ans == -1 || ret[4] < ans) {
				ans = ret[4];
				ansCnt = cCnt;
				for (int i = 0; i < ansCnt; i++) ansArr[i] = cArr[i] + 1;
			} else if (ret[4] == ans) {
				string s1 = "", s2 = "";
				for (int i = 0; i < ansCnt; i++) s1 += to_string(ansArr[i]);
				for (int i = 0; i < cCnt; i++) s2 += to_string(cArr[i] + 1);
				if (s2 < s1) {
					ansCnt = cCnt;
					for (int i = 0; i < ansCnt; i++) ansArr[i] = cArr[i] + 1;
				}
			}
		}
		return;
	}
	for (int i = k; i < n; i++) {
		cArr[idx] = i;
		solve(idx + 1, i + 1, cCnt + 1, tCnt);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < 4; i++) cin >> mArr[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) cin >> sArr[i][j];

	for (int i = 1; i <= n; i++) {
		solve(0, 0, 0, i);
	}

	if (ans == -1) cout << ans;
	else {
		cout << ans << "\n";
		for (int i = 0; i < ansCnt; i++) cout << ansArr[i] << " ";
	}
}