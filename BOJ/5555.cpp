#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    int ans = 0;
    while(n--) {
        int chk = 0;
        string str; cin >> str;
        for(int i = 0; i < (int)str.size(); i++) {
            string tmp = "";
            for(int j = 0; j < (int)s.size(); j++) {
                tmp += str[(i+j)%(int)str.size()];
            }
            if(tmp == s) chk = 1;
        }
        if(chk) ans++;
    }
    cout << ans;
}