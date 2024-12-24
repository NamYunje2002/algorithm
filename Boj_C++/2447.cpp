#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[6562][6562];

void solve(int x, int y, int k) {
    for(int i = x; i < x+k; i++) {
        for(int j = y; j < y+k; j++) {
            arr[i][j] = 1;
        }
    }
    if(x+k*3 > 0 && y > 0 && x+k*3 < n && y < n) {
        if(!arr[x+k*3][y]) solve(x+k*3, y, k);
    }
    if(x > 0 && y+k*3 > 0 && x < n && y+k*3 < n) {
        if(!arr[x][y+k*3]) solve(x, y+k*3, k);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int m = n/3;
    while(m) {
        solve(m, m, m);
        m /= 3;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (arr[i][j] ? " " : "*");
        }
        cout << "\n";
    }
}