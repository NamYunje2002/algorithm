#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, ans = -1; cin >> n;
    vector<int> v(n, 0), lds(n, 1), lis(n, 1);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i]) lis[i] = max(lis[i], lis[j]+1);
        }
    }
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            if(v[j] < v[i]) lds[i] = max(lds[i], lds[j]+1);
        }
        ans = max(ans, lis[i]+lds[i]-1);
    }
    cout << ans;
}