#include <bits/stdc++.h>
using namespace std;

int n, c; 
double a, b;

int main() {
    cin >> n >> a >> b >> c;
    vector<int> D(n);
    for (int i = 0; i < n; i++) cin >> D[i];
    sort(D.begin(), D.end(), greater<>());
    double ans = c / a;
    for (int i = 0; i < n; i++) {
        a += b;
        c += D[i];
        ans = max(ans, c / a);
    }
    cout << (int)ans;
}