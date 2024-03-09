#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int st = 0x7f7f7f7f, en = -1;
int arr[1000001];
ll ans;
ll leftPrefixSum[1000005], rightPrefixSum[1000005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int g, x; cin >> g >> x;
        arr[x] = g;
        st = min(st, x);
        en = max(en, x);
    }
    for(int i = 1; i < 1000001; i++) {
        leftPrefixSum[i] = leftPrefixSum[i - 1] + arr[i];
        rightPrefixSum[1000001 - i] = rightPrefixSum[1000002 - i] + arr[1000001 - i];
    }
    for(int i = st; i <= en; i++) {
        ll sum = arr[i];
        if(i-1-k >= 0) sum += (leftPrefixSum[i-1] - leftPrefixSum[i-1-k]);
        else sum += leftPrefixSum[i-1];
        if(i+1+k <= 1000000) sum += (rightPrefixSum[i+1] - rightPrefixSum[i+1+k]);
        else sum += rightPrefixSum[i+1];
        ans = max(ans, sum);      
    }
    cout << ans;
}