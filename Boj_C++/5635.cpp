#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<pair<string, int>, pair<int, int> > > v(n);
    for(int i = 0; i < n; i++) {
       cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
    }
    sort(v.begin(), v.end());
    cout << v[n-1].first.first << '\n' << v[0].first.first;
}