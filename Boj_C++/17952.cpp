#include <bits/stdc++.h>
using namespace std;

#define A first
#define T second

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);    
    int n; cin >> n;
    int ans = 0;
    pair<int ,int> cur = {0, -1};
    stack<pair<int, int> > st;
    while(n--) {
        int m; cin >> m;
        int a, t;
        if(m == 0) {
            if(!st.empty() && cur.T == -1) {
                cur = st.top();
                st.pop();
            }
        } else {
            int a, t; cin >> a >> t;
            if(cur.T != -1) st.push(cur);
            cur = {a, t};
        }
        if(cur.T > 0) cur.T--;
        if(cur.T == 0) {
            ans += cur.A;
            cur = {0, -1};
        }
    }
    cout << ans;
}