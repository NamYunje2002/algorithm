#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string n; cin >> n;
    int b; cin >> b;
    int ans = 0;
    for(int i = 0; i < (int)n.size(); i++) {
        int t = 1;
        for(int j = 0; j < (int)n.size() - i - 1; j++) t *= b;
        if('A' <= n[i] && n[i] <= 'Z') ans += t * (n[i]-55);
        else ans += t*(n[i]-'0');
    }
    cout << ans;
}