#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, cnt, ans;
int parent[302];
vector<pair<int, pair<int, int> > > edge;

bool cmp(pair<int, pair<int, int> > &p1, pair<int, pair<int, int> > &p2) {
    return p1.X < p2.X;
}

int Find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int a = Find(x), b = Find(y);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int cost; cin >> cost;
        edge.push_back({cost, {0, i}});
    }
    for(int i = 1; i <= n; i++) {   
        for(int j = 1; j <= n; j++) {
            int cost; cin >> cost;
            if(i != j) edge.push_back({cost, {i, j}});
        }
    }
    for(int i = 1; i <= n; i++) parent[i] = i;
    sort(edge.begin(), edge.end(), cmp);
    for(int i = 0; i < n*n; i++) {
        int cost = edge[i].X, a = edge[i].Y.X, b = edge[i].Y.Y;
        if(Find(a) == Find(b)) continue;
        Union(a, b);
        cnt++;
        ans += cost;
        if(cnt == n) break;
    }
    cout << ans;
}