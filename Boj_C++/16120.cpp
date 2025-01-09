#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    stack<char> st;
    for (int i = 0; i < (int)s.size(); i++) {
        st.push(s[i]);
        if (st.size() >= 4) {
            string t = "";
            for (int j = 0; j < 4; j++) {
                t += st.top();
                st.pop();
            }
            if (t == "PAPP") {
                st.push('P');
            } else {
                for (int j = 3; j >= 0; j--) {
                    st.push(t[j]);
                }
            }
        }
    }
    if (st.size() == 1 && st.top() == 'P') cout << "PPAP";
    else cout << "NP";
}