#include <bits/stdc++.h>
using namespace std;

int vis[200002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); 
	for (int i = 0; i < 200002; i++) vis[i] = -1;
	int n, k; cin >> n >> k;
	queue<int> q;
	vis[n] = n;
	q.push(n);
	while (1) {
		int cur = q.front(); q.pop();
		if (cur == k) break;
		if (cur * 2 < k * 2 + 1 && vis[cur * 2] == -1) {
			vis[cur * 2] = cur;
			q.push(cur * 2);
		}

		if (cur + 1 < k * 2 + 1 && vis[cur + 1] == -1) {
			vis[cur + 1] = cur;
			q.push(cur + 1);
		}

		if (cur - 1 > -1 && vis[cur - 1] == -1) {
			vis[cur - 1] = cur;
			q.push(cur - 1);
		}
	}
	int ans = 0;
	stack<int> st;
	while (k != vis[k]) {
		ans++;
		st.push(k);
		k = vis[k];
	}
	cout << ans << "\n" << n << " ";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}