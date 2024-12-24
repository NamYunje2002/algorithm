#include <bits/stdc++.h>
using namespace std;

int vis[55];
vector<int> adj[55];

bool cmp(pair<int, int> &v1, pair<int, int> &v2) {
    if (v1.first == v2.first) return v1.second < v2.second;
    return v1.first < v2.first;
}

int main() {
    int n; cin >> n;
    while (1) {
        int a, b; cin >> a >> b;
        if (a == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int, int> > ans;
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = -1;
        Q.push(i);
        int cnt = 0;
        vis[i] = 0;
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (int j = 0; j < (int)adj[cur].size(); j++) {
                int nxt = adj[cur][j];
                if (vis[nxt] != -1) continue;
                vis[nxt] = vis[cur] + 1;
                cnt = max(cnt, vis[nxt]);
                Q.push(nxt);
            }
        }
        ans.push_back({cnt, i});
    }
    sort(ans.begin(), ans.end(), cmp);
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i].first != ans[0].first) break;
        mn++;
        Q.push(ans[i].second);
    }
    cout << ans[0].first << ' ' << mn << '\n';
    while (!Q.empty()) {
        cout << Q.front() << ' ';
        Q.pop();
    }
}