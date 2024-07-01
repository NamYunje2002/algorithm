#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int dx[2] = {1, -1};
    int ans = 0;
    int n; cin >> n;
    vector<int> A(n+1,0), vis(n+1,0);
    for(int i = 1; i <= n; i++) cin >> A[i];
    int s; cin >> s;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < 2; i++) {
            int nxt = cur + A[cur] * dx[i];
            if(1 > nxt || nxt > n || vis[nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
        }
    }
    for(int i = 1; i <= n; i++) if(vis[i]) ans++;
    cout << ans;
}