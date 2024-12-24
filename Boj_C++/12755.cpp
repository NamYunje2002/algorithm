#include <bits/stdc++.h>
using namespace std;

int n, cnt, rn;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(cnt < n) {
        rn++;
        cnt += to_string(rn).size();
    }
    cout << to_string(rn)[to_string(rn).size()-1-(cnt-n)];
}