#include <bits/stdc++.h>
using namespace std;

int a, b, ans;
int isPrime[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i < 100001; i++) isPrime[i] = 1;
    for(int i = 2; i * i <= 100001; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * i; j < 100001; j+=i) {
            isPrime[j] = 0;
        }
    }
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        int cnt = 0, k = i;
        for(int j = k; j > 1; j--) {
            if(!isPrime[j]) continue;
            if(k % j == 0) {
                k /= j;
                j = k+1;
                cnt++;
            }
        }
        if(isPrime[cnt]) ans++;
    }   
    cout << ans;
}