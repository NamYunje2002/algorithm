#include <bits/stdc++.h>
using namespace std;

int n, t, p, ans;
int arr[6];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < 6; i++) cin >> arr[i];
    cin >> t >> p;
    for(int i = 0; i < 6; i++) {
        ans += (arr[i]/t+1);
        if(arr[i]%t==0)ans--;
    }   
    cout << ans << '\n' << n/p << ' ' << n%p;
}