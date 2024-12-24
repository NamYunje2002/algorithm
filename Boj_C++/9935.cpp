#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    stack<char> st;
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < (int)s1.size(); i++) {
        st.push(s1[i]);
        if(st.top() == s2[0] && st.size() >= (int)s2.size()) {
            string tmp = "";
            for(int j = 0; j < (int)s2.size(); j++) {
                tmp += st.top();
                st.pop();
            }
            if(tmp != s2) {
                reverse(tmp.begin(), tmp.end());
                for(int j = 0; j < (int)s2.size(); j++) {
                    st.push(tmp[j]);
                }
            }
        }
    }
    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    if(ans == "") cout << "FRULA";
    else {
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i];
        }
    }
}