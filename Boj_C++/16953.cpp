// https://www.acmicpc.net/problem/16953

// BFS
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

// 그리디
#include <iostream>

using namespace std;

long long a, b, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	while (1) {
		++ans;
		if (a == b)
			break;
		else if (a > b) {
			ans = -1;
			break;
		}
		if (b % 10 == 1) {
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			ans = -1;
			break;
		}
	}
	cout << ans;
}

// DFS
#include <iostream>

using namespace std;

int ans = 10000002;
long long a, b;

void dfs(long long a, int cnt) {
	if (a > b)
		return;
	if (a == b) 
		ans = min(cnt, ans);
	dfs(a * 2, cnt + 1);
	dfs(a * 10 + 1, cnt + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	dfs(a, 1);
	if (ans == 10000002) 
		cout << -1;
	else 
		cout << ans;
}
