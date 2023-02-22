// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, k, m, v, c, idx, bag[300000];
long long ans;
pair<int, int> gem[300000];
priority_queue<int, vector<int>, less<int> >pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		gem[i] = { m, v };
	}
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(gem, gem + n);
	sort(bag, bag + k);
	for (int i = 0; i < k; i++) {
		while (idx < n && bag[i] >= gem[idx].X) {
			pq.push(gem[idx].Y);
			idx++;
		}
		if (pq.empty()) continue;
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}
