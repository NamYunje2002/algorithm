#include <bits/stdc++.h>
using namespace std;

int v, e, ans;
int vis[10005], p[10005];
vector<int> adj[10005];
stack<int> st;

int solve(int cur) {
    st.push(cur);
    p[cur] = cur;
    int parent = cur;
    for (auto nxt : adj[cur]) {
        if (!p[nxt]) {
            parent = nxt;
            break;
        } else {
            return solve(cur);
        }
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        int parent = solve(i);
    }
}