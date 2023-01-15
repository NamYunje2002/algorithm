// https://www.acmicpc.net/problem/11404

#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, g[102][102], d[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		fill(d[i], d[i] + n + 1, INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for(int i = 1; i <= n; i++) 
		d[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (d[i][j] == INF ? 0 : d[i][j]) << " ";
		}
		cout << "\n";
	}
}
