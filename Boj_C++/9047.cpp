#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ans = 0;
        while ("6174" != s) {
            ans++;
            vector<char> v1(4), v2(4);
            for (int i = 0; i < 4; i++) v1[i] = v2[i] = s[i];
            sort(v1.begin(), v1.end(), greater<>());
            sort(v2.begin(), v2.end());
            string s1 = "", s2 = "";
            for (int i = 0; i < 4; i++) {
                if (v1[i] != '0' || (v1[i] == '0' && s1.size())) s1 += v1[i];
                if (v2[i] != '0' || (v2[i] == '0' && s2.size())) s2 += v2[i];
            }
            s = to_string(stoi(s1) - stoi(s2));
            int k = 4 - (int)s.size();
            while (k--) {
                s.insert(0, "0");
            }
        }
        cout << ans << '\n';
    }
}