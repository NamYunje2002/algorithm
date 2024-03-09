#include <bits/stdc++.h>
using namespace std;
#define MOD 1234567891
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll ans = 0, p = 1;
    int l; 
    string s;
    cin >> l >> s;
    for(int i = 0; i <(int)s.size(); i++) {
       ans = (ans + ((s[i] - 96)) * p) % MOD;
       p = (p*31) % MOD;
    }
    cout << ans;
}