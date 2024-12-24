#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string p; cin >> p;
    string f = "", b = "";
    int chk = 0;
    for(int i = 0; i < (int)p.size(); i++) {
        if(p[i] == '*') {
            chk = 1;
            continue;
        }
        if(chk) b += p[i];
        else f += p[i];
    }
    while(n--) {
        string s; cin >> s;
        int chk = 1;
        if((int)s.size() < (int)f.size()+(int)b.size()) chk = 0;
        for(int i = 0; i < (int)f.size(); i++) {
            if(f[i] != s[i]) chk = 0;
        }
        int idx = (int)s.size() - 1;
        for(int i = (int)b.size()-1; i >= 0; i--) {
            if(b[i] != s[idx]) chk = 0;
            idx--;
        }
        if(chk) cout << "DA\n";
        else cout << "NE\n";
    }
}