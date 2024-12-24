#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s, p; cin >> s >> p;
        int ans = (int)s.size();
        for(int i = 0; i <= (int)s.size()-(int)p.size(); i++) {
            int chk = 1;
            for(int j = 0; j < (int)p.size(); j++) {
                if(s[i+j] != p[j]) {
                    chk = 0;
                    break;
                }
            }
            if(chk) {
                ans -= ((int)p.size() - 1);
                i += ((int)p.size() - 1);
            }
        }
        cout << ans << '\n';
    }
}