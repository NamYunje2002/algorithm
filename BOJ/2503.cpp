#include <bits/stdc++.h>
using namespace std;

int cnt, ans[1000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(ans, ans+1000, 1);
    int n; cin >> n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int i = 100; i < 1000; i++) {
            if(!ans[i]) continue;
            string t = to_string(i);
            if(t[0] == '0' || t[1] == '0' || t[2] == '0') {
                ans[i] = 0;
                continue;
            } 
            if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) {
                ans[i] = 0;
                continue;
            }
            string s = to_string(a);
            int st = 0, ba = 0;
            for(int i = 0; i < 3; i++) if(t[i] == s[i]) st++;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(i != j && t[i] == s[j]) ba++;
                }
            }
            if(st != b || ba != c) ans[i] = 0;
        }
    }
    for(int i = 100; i < 1000; i++) if(ans[i]) cnt++;
    cout << cnt;
}