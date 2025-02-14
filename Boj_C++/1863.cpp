#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.X < p2.X;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].X >> v[i].Y;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    stack<int> st;
    st.push(0);
    for (int i = 0; i < n; i++) {
        pair<int, int> cur = v[i];
        if (st.top() < cur.Y) {
            ans++;
            st.push(cur.Y);
        } else {
            while (st.top() > cur.Y) st.pop();
            if (st.top() != cur.Y) ans++;
            if (cur.Y != 0) st.push(cur.Y);
        }
    }
    cout << ans;
}