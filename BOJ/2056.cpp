#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int deg[10002], t[10002], dp[10002];
vector<int> adj[10002];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int c; 
        cin >> t[i] >> c;
        for(int j = 0; j < c; j++) {
            int x; cin >> x;
            adj[x].push_back(i);
            deg[i]++;
        }
    }  
    for(int i = 1; i <= n; i++) {
        if(!deg[i]) {
            q.push(i);
            dp[i] = t[i];
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[cur], dp[nxt]);
            if(deg[nxt] == 0) {
                q.push(nxt);
                dp[nxt] += t[nxt];
            }
        }
    }
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
}