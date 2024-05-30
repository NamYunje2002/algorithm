#include <bits/stdc++.h>
using namespace std;

map<char, pair<char, char> > g;

void pre(char c) {
    if(c == '.') return;
    printf("%c", c);
    pre(g[c].first);
    pre(g[c].second);
}

void in(char c) {
    if(c == '.') return;
    in(g[c].first);
    printf("%c", c);
    in(g[c].second);
}

void post(char c) {
    if(c == '.') return;
    post(g[c].first);
    post(g[c].second);
    printf("%c", c);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        g[s[0]] = make_pair(s[2], s[4]);
    }
    pre('A');
    printf("\n");
    in('A');
    printf("\n");
    post('A');
    printf("\n");
}