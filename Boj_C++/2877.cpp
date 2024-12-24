#include <bits/stdc++.h>
using namespace std;

int t[30];
string ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int k; cin >> k;
    t[0] = 0;
    for (int i = 1; i < 30; i++) {
        t[i] = t[i-1] + pow(2, i);
    }

    for (int i = 1; i < 30; i++) {
        if (t[i-1] >= k) break;
        int n = (int)pow(2, i);
        int m = k % n;
        int p = n-1;
        if (m == p || (m < (p+(n/2))%n)) ans += '4';
        else ans += '7';
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}