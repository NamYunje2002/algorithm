#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
int arr[15];

void solve(int idx, int sum) {
    if(sum >= n) {
        if(sum == n) {
            cnt++;
            if(cnt == k) {
                for(int i = 0; i < idx-1; i++) cout << arr[i] << "+";
                cout << arr[idx-1];
                exit(0);
            }
        }
        return;
    }
    for(int i = 1; i <= 3; i++) {
        arr[idx] += i;
        solve(idx+1, sum + arr[idx]);
        arr[idx] -= i;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    solve(0, 0);
    cout << -1;
}