#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt = 0;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    stack<char> st;
    for (int i = 0; i < (int)s.size(); i++) {
        while (cnt < k && !st.empty() && st.top() < s[i]) {
            st.pop();
            cnt++;
        }
        st.push(s[i]);
    }
    string ans = "";
    for (int i = cnt; i < k; i++) st.pop();
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}