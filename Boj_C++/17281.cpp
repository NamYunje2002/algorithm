#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[51][10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> seq(8);
	for (int i = 0; i < 8; i++) {
		seq[i] = i + 1;
	}
	int ans = 0;
	do {
		int score = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			int outCnt = 0;
			int status[4] = { 0, 0, 0, 0 };
			while (outCnt < 3) {
				int player = 0;
				if (cur < 3) player = seq[cur];
				else if (cur > 3) player = seq[cur - 1];
				if (arr[i][player] == 0) {
					outCnt++;
				} else if (arr[i][player] == 1) {
					status[3] = status[2];
					status[2] = status[1];
					status[1] = status[0];
					status[0] = 1;
				} else if (arr[i][player] == 2) {
					status[3] = status[2] + status[1];
					status[2] = status[0];
					status[1] = 1;
					status[0] = 0;
				} else if (arr[i][player] == 3) {
					status[3] = status[2] + status[1] + status[0];
					status[2] = 1;
					status[1] = status[0] = 0;
				} else if (arr[i][player] == 4) {
					status[3] = status[2] + status[1] + status[0] + 1;
					status[2] = status[1] = status[0] = 0;
				}
				score += status[3];
				status[3] = 0;
				cur = (cur + 1) % 9;
			}
		}
		ans = max(ans, score);
	} while (next_permutation(seq.begin(), seq.end()));
	cout << ans;
}