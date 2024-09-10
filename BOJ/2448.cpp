#include <bits/stdc++.h>
using namespace std;

int n;
char arr[3100][6200];

void solve(int x, int y, int m) {
    if (m == 3) {
        arr[x][y] = '*';
        arr[x+1][y-1] = arr[x+1][y+1] = '*';
        for(int i = 0; i < 5; i++) arr[x+2][y-2+i] = '*';
        return;
    }
    solve(x, y, m/2);
    solve(x+m/2, y-m/2, m/2);
    solve(x+m/2, y+m/2, m/2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            arr[i][j] = ' ';
        }
    }
    solve(0, n-1, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}