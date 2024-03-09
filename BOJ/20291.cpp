#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string, int> mp;
    
    while(n--) {
        int chk = 0;
        string ex = "";
        string s; cin >> s;
        for(int i = 0; i < (int)s.size(); i++) {
            if(chk) ex += s[i];
            if(s[i] == '.') chk = 1;
        }
        mp[ex]++;
    }
    for(auto iter = mp.begin(); iter != mp.end(); iter++) {
        cout << iter->first << ' ' << iter->second << '\n';
    }
}