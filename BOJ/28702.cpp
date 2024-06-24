#include <bits/stdc++.h>
using namespace std;

int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 3; i++) {
        string s; cin >> s;
        if(s == "FizzBuzz" || s == "Fizz" || s == "Buzz" || ans) continue;
        ans = stoi(s);
        ans += 3-i;
    }
    if(ans % 15 == 0) cout << "FizzBuzz";
    else if(ans % 5 == 0) cout << "Buzz";
    else if(ans % 3 == 0) cout << "Fizz";
    else cout << ans;   
}