#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> pSeq(n);
	for (int i = 0; i < n; i++) cin >> pSeq[i];
	vector<int> sSeq(n);
	for (int i = 0; i < n; i++) cin >> sSeq[i];

	vector<int> start(n);
	for (int i = 0; i < n; i++) start[i] = i;

	set<vector<int> > st;
	int ans = -1;
	queue<pair<vector<int>, int> > q;
	st.insert(start);
	q.push({ start, 0 });
	while (!q.empty()) {
		vector<int> cur = q.front().X;
		int cnt = q.front().Y;
		q.pop();
		int chk = 1;
		for (int i = 0; i < n; i++) {
			if (i % 3 != pSeq[cur[i]]) chk = 0;
		}
		if (chk) {
			ans = cnt;
			break;
		}
		vector<int> nxt = cur;
		for (int i = 0; i < n; i++) {
			nxt[sSeq[i]] = cur[i];
		}
		if (st.find(nxt) == st.end()) {
			st.insert(nxt);
			q.push({ nxt, cnt + 1 });
		}
	}
	cout << ans;
}