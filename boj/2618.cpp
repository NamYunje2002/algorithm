// https://www.acmicpc.net/problem/2618

#include <iostream>
#include <cstring>

#define X first
#define Y second

using namespace std;

int n, w, x, y, dp[1002][1002];
pair<int, int> map[1002];

int getDist(pair<int, int> cur, pair<int, int> target) {
	return abs(cur.X - target.X) + abs(cur.Y - target.Y);
}

int getTotal(int p1, int p2) {
	if (p1 == w || p2 == w) return 0;
	if (dp[p1][p2] != -1) return dp[p1][p2];

	int nxt = max(p1, p2) + 1;
	int dist1 = 0, dist2 = 0;
    
	if (p1 == 0) dist1 = getDist({ 1, 1 }, map[nxt]);
	else dist1 = getDist(map[p1], map[nxt]);
    
	if (p2 == 0) dist2 = getDist({ n, n }, map[nxt]);
	else dist2 = getDist(map[p2], map[nxt]);

	dist1 += getTotal(nxt, p2);
	dist2 += getTotal(p1, nxt);
	dp[p1][p2] = min(dist1, dist2);
	return dp[p1][p2];
}

void getNum(int p1, int p2) {
	if (p1 == w || p2 == w) return;

	int nxt = max(p1, p2) + 1;
	int dist1 = 0, dist2 = 0;
	
	if (p1 == 0) dist1 = getDist({ 1, 1 }, map[nxt]);
	else dist1 = getDist(map[p1], map[nxt]);
    
	if (p2 == 0) dist2 = getDist({ n, n }, map[nxt]);
	else dist2 = getDist(map[p2], map[nxt]);

	if (dp[nxt][p2] + dist1 < dp[p1][nxt] + dist2) {
		cout << 1 << "\n";
		getNum(nxt, p2);
	}
	else {
		cout << 2 << "\n";
		getNum(p1, nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> w;
	for (int i = 1; i <= w; i++) 
		cin >> map[i].X >> map[i].Y;
	cout << getTotal(0, 0) << "\n";
	getNum(0, 0);
}
