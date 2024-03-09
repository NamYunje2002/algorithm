#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> deg(n+1, 0);
        vector<int> dp(n+1, 0);
        vector<int> ans(n+1, 0);
        vector<int> adj[1001];
        for(int i = 1; i <= n; i++) cin >> ans[i];
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            deg[y]++;
        }   
        queue<int> q;
        for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]) {
                deg[nxt]--;
                dp[nxt] = max(dp[nxt], ans[cur]);
                if(deg[nxt] == 0) {
                    ans[nxt] += dp[nxt];
                    q.push(nxt);
                }
            }
        }
        int w; cin >> w;
        cout << ans[w] << '\n';
    }
}