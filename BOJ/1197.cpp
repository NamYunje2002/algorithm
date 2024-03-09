#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e;
vector<pair<int, int> > adj[10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
}