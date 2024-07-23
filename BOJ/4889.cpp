#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k = 0;
    while(++k) {
        string s; cin >> s;
        if(s[0] == '-') break;
        int ans = 0;
        stack<char> st;
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] == '{') st.push('{');
            else {
                if(!st.empty()) {
                    st.pop();
                } else {
                    ans++;
                    st.push('{');
                }
            }
        }
        cout << k << ". " << ans + st.size() / 2 << "\n";
    }
}