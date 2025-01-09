#include <bits/stdc++.h>
using namespace std;

int m, n;
string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

bool cmp(pair<string, int> p1, pair<string,int> p2) {
    return p1.first < p2.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    vector<pair<string, int> > v(n - m + 1);
    for (int i = m; i <= n; i++) {
        string rsl = "";
        string s = to_string(i);
        for (int j = 0; j < (int)s.size(); j++) {
            rsl += arr[s[j] - '0'] + " ";
        }
        v[i - m] = {rsl, i};
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i <= n - m + 1; i++) {
        cout << v[i - 1].second << " \n"[i % 10 == 0];
    }
}