#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		priority_queue<int, vector<int>, less<int> > maxPQ;
		priority_queue<int, vector<int>, greater<int> > minPQ;
		int m; cin >> m;
		int cnt = 0;
		vector<int> ans((m - 1) / 2 + 1);
		while (m--) {
			int x; cin >> x;
			if (maxPQ.empty()) {
				maxPQ.push(x);
			} else {
				if (minPQ.empty()) {
					if (maxPQ.top() > x) maxPQ.push(x);
					else minPQ.push(x);
				}
				else {
					if (minPQ.top() < x) minPQ.push(x);
					else maxPQ.push(x);
				}
			}
			if (maxPQ.size() != minPQ.size() && (maxPQ.size() + minPQ.size()) % 2 == 0) {
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			if (minPQ.size() > maxPQ.size()) {
				maxPQ.push(minPQ.top());
				minPQ.pop();
			}
			if (m % 2 == 0) ans[cnt++] = maxPQ.top();
		}
		cout << (int)ans.size() << "\n";
		for (int i = 0; i < (int)ans.size(); i++) {
			if (i >= 10 && i % 10 == 0) cout << "\n";
			cout << ans[i] << " ";	
		}
		cout << "\n";
	}
}