#include <bits/stdc++.h>
using namespace std;

int main() {
    int c = 0, j = 0, e = 0;
    string s; cin >> s;
    string ans = "";
    for (int i = 0; i < (int)s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            j = 1;
            if (i == 0) {
                e = 1;
                break;
            }
            ans += "_";
            ans += s[i] + ('a' - 'A');
        } else if ('_' == s[i]) {
            c = 1;
            if (i == 0 || i == (int)s.size() - 1) {
                e = 1;
                break;
            }
            if ('A' <= s[i + 1] && s[i + 1] <= 'Z' || s[i + 1] == '_') {
                e = 1;
                break;
            }
            ans += s[++i] - ('a' - 'A');
        } else if ('a' <= s[i] && s[i] <= 'z') {    
            ans += s[i];
        }
    }
    if (e || (c && j)) ans = "Error!";
    cout << ans;
}