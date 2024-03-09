#include <bits/stdc++.h>
using namespace std;

int n, m;

int Find(int x, vector<int> &v) {
    if(x == v[x]) return x;
    return x = Find(v[x], v);
}

void Union(int x, int y, vector<int> &v) {
    int a = Find(x, v);
    int b = Find(y, v);
    if(a < b) v[b] = a;
    else v[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; i++) v[i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x==1) Union(i, j, v);
        }
    }
    int pre = -1;
    string ans = "YES";
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        int y = Find(x, v);
        if(pre == -1) pre = y;
        if(pre != y) ans = "NO";
    }   
    cout << ans;
}