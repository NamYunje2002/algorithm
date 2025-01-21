#include <bits/stdc++.h>
using namespace std;

int cnt1[26];

int main() {
    int ans = 0;
    int n; cin >> n;
    string s1; cin >> s1;
    for (int i = 0; i < (int)s1.size(); i++) {
        cnt1[s1[i] - 'A']++;
    }
    n--;
    while (n--) {
        int cnt = 0;
        string s2; cin >> s2;
        vector<int> cnt2(26, 0);
        for (int i = 0; i < (int)s2.size(); i++) {
            cnt2[s2[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            cnt += abs(cnt1[i] - cnt2[i]);
        }
        if (cnt <= 1) ans++;
        else if (cnt == 2 && s2.size() == s1.size()) ans++;
    }
    cout << ans;
}