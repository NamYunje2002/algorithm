#include <bits/stdc++.h>
using namespace std;

int a[27];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    while(n--) {
        int cnt = 0;
        string s; getline(cin, s);
        for(int i = 0; i < (int)s.size(); i++) {
            if('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
            if('a' <= s[i] && s[i] <= 'z') {
                if(a[s[i] - 'a'] == 0) cnt++;
                a[s[i] - 'a'] = 1;
            }
        }   
        if(cnt == 26) cout << "pangram\n";
        else {
            cout << "missing ";
            for(int i = 0; i < 26; i++) {
                if(!a[i]) cout << char('a'+i);
            }
            cout << "\n";
        }
        for(int i = 0; i < 27; i++) a[i] = 0;
    }
}