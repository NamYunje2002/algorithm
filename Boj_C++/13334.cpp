#include <bits/stdc++.h>
using namespace std;

#define X1 first
#define X2 second

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.X2 == p2.X2) return p1.X1 < p2.X1;
	return p1.X2 < p2.X2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].X1 >> v[i].X2;
		if (v[i].X1 > v[i].X2) swap(v[i].X1, v[i].X2);
	}
	sort(v.begin(), v.end(), cmp);
	int d; cin >> d;
	int ans = 0;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) {
		pq.push(v[i].X1);
		while (!pq.empty()) {
			if (v[i].X2 - d <= pq.top()) {
				ans = max(ans, (int)pq.size());
				break;
			}
			pq.pop();
		}
	}
	cout << ans;
}