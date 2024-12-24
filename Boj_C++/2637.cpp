#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int deg[102], dp[102], isNotBasic[102];
queue<int> q;
vector<pair<int, int> > adj[102];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int midPoint = n;
    while(m--) {
        int x, y, k; cin >> x >> y >> k;
        isNotBasic[x] = 1; 
        adj[x].push_back({y, k});
        deg[y]++;
    }
    for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
    dp[n] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(pair<int, int> nxt : adj[cur]) {
            int nxtNum = nxt.X, nxtCnt = nxt.Y;
            deg[nxtNum]--;
            dp[nxtNum] += dp[cur] * nxtCnt;
            if(deg[nxtNum] == 0) {
                q.push(nxtNum);
            }
        }
    }
    for(int i = 1; i < midPoint; i++) if(!isNotBasic[i]) cout << i << ' ' << dp[i] << '\n';
}