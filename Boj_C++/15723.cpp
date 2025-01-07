#include <bits/stdc++.h>
using namespace std;

int vis[30];
vector<int> adj[30];

int cToI(char c) {
    return (int)c - 97;
}

void dfs(int cur, int t) {
    if (cur == t) return;
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        dfs(nxt, t);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        char a, b;
        string s;
        cin >> a >> s >> b;
        adj[cToI(a)].push_back(cToI(b));
    }
    int m; cin >> m;
    while (m--) {
        char a, b;
        string s;
        cin >> a >> s >> b;
        for (int i = 0; i < 30; i++) vis[i] = 0;
        vis[cToI(a)] = 1;
        dfs(cToI(a), cToI(b));
        cout << (vis[cToI(b)] ? "T" : "F") << "\n";
    }
}