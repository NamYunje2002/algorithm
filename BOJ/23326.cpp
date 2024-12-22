#include <bits/stdc++.h>
using namespace std;

int n, q, cur;
set<int> st;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (m) st.insert(i);
    } 
    while (q--) {
        int m; cin >> m;
        if (m == 1) {
            int i; cin >> i;
            i--;
            if (st.find(i) != st.end()) st.erase(i);
            else st.insert(i);
        } else if (m == 2) {
            int x; cin >> x;
            cur = (cur + x) % n;
        } else if (m == 3) {
            if (st.empty()) cout << "-1\n";
            else {
                auto iter = st.lower_bound(cur);
                if (iter != st.end()) cout << *iter - cur << "\n";
                else cout << *st.begin() + n - cur << "\n";
            }
        }
    }
}