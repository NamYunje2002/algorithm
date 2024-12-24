#include <bits/stdc++.h>
using namespace std;

bool know[52];
int party[52][52];

int Find(int x, vector<int> &v) {
    if(x == v[x]) return x;
    return Find(v[x], v);
}

void Union(int x, int y, vector<int> &v) {
    int a = Find(x, v);
    int b = Find(y, v);
    if(know[a]) v[b] = a;
    else v[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);    
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        know[x] = 1;
    }
    
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) v[i] = i;
    for(int i = 0; i < m; i++) {
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++) cin >> party[i][j];
        for(int j = 0; j < cnt-1; j++) Union(party[i][j], party[i][j+1], v);
    }

    int ans = m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(know[Find(party[i][j], v)]) {
                ans--;
                break;
            }
        }
    }
    cout << ans;
}