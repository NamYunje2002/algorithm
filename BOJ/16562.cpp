#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
int cost[10005], parent[10005], arr[10005];

int Find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if(cost[pa] < cost[pb]) parent[pb] = pa;
    else parent[pa] = pb;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        Union(x, y);
    }
    for(int i = 1; i <= n; i++) {
        Find(i);
        arr[parent[i]] = 1;
    }
    for(int i = 1; i <= n && ans <= k; i++) if(arr[i]) ans += cost[i];
    if(ans <= k) cout << ans;
    else cout << "Oh no";
}