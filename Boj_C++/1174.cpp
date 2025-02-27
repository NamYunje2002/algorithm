#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string ans = "-1";

void solve(string ret, int cur, int len) {
    if ((int)ret.size() == len) {
        cnt++;
        if (cnt == n) ans = ret;
        return;
    }
    for (int i = 0; i < cur; i++) {
        solve(ret + to_string(i), i, len);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 9; j++) {
            solve(to_string(j), j, i);
        }
    }
    cout << ans;
}