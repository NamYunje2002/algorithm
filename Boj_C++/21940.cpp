#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int c[205], mx[205];
int d[205][205];
priority_queue<int,vector<int>,greater<int> > pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }    
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int z = 1; z <= n; z++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][z]+d[z][j]);
            }
        }
    }
    int k; cin >> k;
    for(int i = 0; i < k; i++) cin >> c[i];
    int mn = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            mx[i] = max(mx[i], d[i][c[j]] + d[c[j]][i]);
        }
        mn = min(mn, mx[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(mn == mx[i]) pq.push(i);
    }
    while(!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
}