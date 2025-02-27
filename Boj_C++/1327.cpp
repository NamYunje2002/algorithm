#include <bits/stdc++.h>
using namespace std;

int n, k;
string sortedStr;
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        sortedStr += s;
    }
    string str = sortedStr;
    sort(sortedStr.begin(), sortedStr.end());
    queue<string> q;
    mp[str] = 1;
    q.push(str);
    while (!q.empty()) {
        string s = q.front(); q.pop();
        if (s == sortedStr) break;
        for (int i = 0; i <= n - k; i++) {
            string tmp = s;
            reverse(tmp.begin() + i, tmp.begin() + i + k);
            if (mp[tmp] < 1) {
                mp[tmp] = mp[s] + 1;
                q.push(tmp);
            }
        }
    }
    cout << mp[sortedStr] - 1;
}