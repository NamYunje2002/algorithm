#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans[502], deg[502], dp[502];
vector<int> g[502];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ans[i];
        while(1) {
            int x; cin >> x;
            if(x == -1) break;
            g[x].push_back(i);
            deg[i]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < (int)g[cur].size(); i++) {
            int nxt = g[cur][i];
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], ans[cur]);
            if(!deg[nxt]) {
                ans[nxt] += dp[nxt];
                q.push(nxt);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
}