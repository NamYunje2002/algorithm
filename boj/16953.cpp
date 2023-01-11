// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <queue>

#define value first
#define count second

using namespace std;

long long a, b, ans = -1;
queue<pair<long long, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	Q.push({ a, 1 });
	while (!Q.empty()) { 
		pair<long long, int> cur = Q.front(); Q.pop();
		if (cur.value == b) {
			ans = cur.count;
			break;
		}
		if (cur.value > b) continue;
		Q.push({ cur.value * 2, cur.count + 1 });
		Q.push({ cur.value * 10 + 1, cur.count + 1 });
	}
	cout << ans;
}
