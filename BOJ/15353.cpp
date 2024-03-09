#include <bits/stdc++.h>
using namespace std;

int main() {
    int c = 0;
    string a, b; cin >> a >> b;
    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i < min((int)a.size(), (int)b.size()); i++) {
        int aNum = a[i]-'0', bNum = b[i]-'0';
        ans += to_string((aNum + bNum + c) % 10);
        if(aNum + bNum + c > 9) c = 1;
        else c = 0;
    }

    if((int)a.size() > (int)b.size()) {
        for(int i = (int)b.size(); i < (int)a.size(); i++) {
            int num = a[i]-'0';
            ans += to_string((num + c) % 10);
            if(num + c > 9) c = 1;
            else c = 0;
        }
    }else if((int)a.size() < (int)b.size()) {
        for(int i = (int)a.size(); i < (int)b.size(); i++) {
            int num = b[i]-'0';
            ans += to_string((num + c) % 10);
            if(num + c > 9) c = 1;
            else c = 0;
        }
    }
    if(c == 1) ans += to_string(c);

    reverse(ans.begin(), ans.end());
    cout << ans;
}