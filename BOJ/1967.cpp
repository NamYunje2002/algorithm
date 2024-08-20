#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[10005];
vector<pair<int, int> > v[10005];

int solve(int k) {
    int mxV = 0;
    queue<int> q;
    q.push(k);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt : v[cur]) {
            if(dist[nxt.X] != -1) continue;
            dist[nxt.X] = dist[cur] + nxt.Y;
            if(dist[nxt.X] > dist[mxV]) mxV = nxt.X;
            q.push(nxt.X);
        }
    }
    return mxV;
}

int main() {
    int n; cin >> n;
    fill(dist, dist+10005, -1);
    for(int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dist[1] = 0;
    int mxV = solve(1);
    
    fill(dist, dist+10005, -1);
    dist[mxV] = 0;
    int ansV = solve(mxV);
    cout << dist[ansV];
}