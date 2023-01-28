// https://www.acmicpc.net/problem/15651

#include <iostream>

using namespace std;

int n, m, arr[9];

void solve(int k) {
    if (k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        solve(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve(0);
}
