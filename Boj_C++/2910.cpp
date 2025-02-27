#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
map<int, int> seq;

bool cmp(int a, int b) {
    if (mp[a] == mp[b]) return seq[a] < seq[b];
    return mp[a] > mp[b];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        if (seq[v[i]] == 0) seq[v[i]] = i + 1;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) cout << v[i] << ' ';
}