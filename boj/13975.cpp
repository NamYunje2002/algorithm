// https://www.acmicpc.net/problem/13975

#include <iostream>
#include <queue>

using namespace std;

int t, k;
long long n, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		priority_queue<long long, vector<long long>, greater<long long>> Q;
		cin >> k;
		while (k--) {
			cin >> n;
			Q.push(n);
		}
		while (Q.size() > 1) {
			n = 0;
			n += Q.top();
			Q.pop();
			n += Q.top();
			Q.pop();
			ans += n;
			Q.push(n);
		}
		cout << ans << "\n";
		ans = 0;
	}
}
