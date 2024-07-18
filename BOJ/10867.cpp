#include <bits/stdc++.h>
using namespace std;

int n;
int vis[2005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(vis[x+1000]) continue;
        vis[x+1000] = 1;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < (int)v.size(); i++) cout << v[i] << " ";
}