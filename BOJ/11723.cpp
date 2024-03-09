#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m; cin >> m;
    while(m--) {
        string s; cin >> s;
        if(s == "add") {
            cin >> x;
            n |= (1<<x);
        }
        if(s == "remove") {
            cin >> x;
            n &= ~(1<<x);
        }
        if(s == "check") {
            cin >> x;
            if(n & (1<<x)) cout << "1\n";
            else cout << "0\n";
        }
        if(s == "toggle") {
            cin >> x; 
            if(n & (1<<x)) n &= ~(1<<x);
            else n |= 1<<x;
        }
        if(s=="all") {
            n = (1<<21)-1;
        }
        if(s=="empty") {
            n = 0;
        }
    }
}