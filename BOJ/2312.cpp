#include <bits/stdc++.h>
using namespace std;

int isPrime[100000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(isPrime, isPrime+100000, 1);
    for(int i = 2; i < 100000; i++) if(isPrime[i]) for(int j = i*2; j < 100000; j+=i) isPrime[j] = 0;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int i = 2, cnt = 0;
        while(1) {
            if(!isPrime[i]) {
                i++;
                continue;
            }
            if(n % i == 0) {
                cnt++;
                n /= i;
            }
            else {
                if(cnt) cout << i << ' ' << cnt << '\n';
                cnt = 0;
                i++;
            }
            if(n == 1) {
                if(cnt) cout << i << ' ' << cnt << '\n';
                cnt = 0;
                i++;
                break;
            }
        }
    }
}