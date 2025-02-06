#include <bits/stdc++.h>
using namespace std;

int ans;
set<string> st;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s, e, q; cin >> s >> e >> q;
    string t, n;
    while (cin >> t >> n) {
        if (st.find(n) == st.end() && t <= s) st.insert(n);
        if (st.find(n) != st.end() && e <= t && t <= q) {
            st.erase(n);
            ans++;
        }
    }
    cout << ans;
}