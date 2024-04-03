#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string ans = "Yes";
    int n, m; cin >> n >> m;
    while(m--) {
        int k; cin >> k;
        int pre = 200001;
        while(k--) {
            int x; cin >> x;
            if(x > pre) ans = "No";
            pre = x;
        }
    }
    cout << ans;
}