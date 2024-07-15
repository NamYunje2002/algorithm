#include <bits/stdc++.h>
using namespace std;

int b,c,d, ans1, ans2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> b >> c >> d;
    vector<int> ba(b, 0);
    vector<int> ca(c, 0);
    vector<int> da(d, 0);
    for(int i = 0; i < b; i++) {
        cin >> ba[i];
        ans1 += ba[i];
    }
    for(int i = 0; i < c; i++) {
        cin >> ca[i];
        ans1 += ca[i];
    }
    for(int i = 0; i < d; i++) {
        cin >> da[i];
        ans1 += da[i];
    }
    sort(ba.begin(), ba.end(), greater<int>());
    sort(ca.begin(), ca.end(), greater<int>());
    sort(da.begin(), da.end(), greater<int>());
    int k = 0;
    for(k; k < min(b, min(c, d)); k++) {
        ans2 += (ba[k] + ca[k] + da[k]) * 0.9;
    }
    for(int i = k; i < b; i++) ans2 += ba[i];
    for(int i = k; i < c; i++) ans2 += ca[i];
    for(int i = k; i < d; i++) ans2 += da[i];
    cout << ans1 << '\n' << ans2;
}