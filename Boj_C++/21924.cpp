#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define X first
#define Y second

int n, m, cnt;
ll sum, total;
int p[100005];

int Find(int x) {
	if (x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	int a = Find(x), b = Find(y);
	if (a < b) p[b] = a;
	else p[a] = b;
}

bool cmp(pair<int, pair<int, int> >& p1, pair<int, pair<int, int> >& p2) {
	return p1.X < p2.X;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 100005; i++) p[i] = i;
	cin >> n >> m;
	vector<pair<int, pair<int, int> > > edgeVector(m);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edgeVector[i] = { c, {a,b} };
		total += c;
	}
	sort(edgeVector.begin(), edgeVector.end(), cmp);
	
	for (int i = 0; i < m; i++) {
		int cost = edgeVector[i].X;
		pair<int, int> edge = edgeVector[i].Y;
		int a = Find(edge.X);
		int b = Find(edge.Y);
		if (p[a] == p[b]) continue;
		Union(a, b);
		sum += cost;
		cnt++;
		if (cnt == n - 1) break;
	}
	for (int i = 1; i <= n; i++) {
		Find(i);
		if (p[1] != p[i]) sum = total + 1;
	}
	cout << total - sum;
}