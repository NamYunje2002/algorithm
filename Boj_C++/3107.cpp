#include <bits/stdc++.h>
using namespace std;

int main() {
    int p = 1, numCnt = 0;
    string s; cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ':') {
            p = 1;
        } else {
            if (p) {
                p = 0;
                numCnt++;
            }
        }
    }
    cout << "Number count : " << numCnt << "\n";
    int cCnt = 0;
    string num;
    vector<string> v;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ':') {
            cCnt++;
            if (cCnt == 2) {
                for (int j = 0; j < 8 - numCnt; j++) {
                    v.push_back("0000");
                }
            } else if ((int)num.size()) {
                int len = (int)num.size();
                for (int j = 0; j < 4 - len; j++) {
                    num.insert(0, "0");
                }
                v.push_back(num);
                num = "";
            }
        } else {
           num += s[i];
           cCnt = 0;
        }
    }
    if (s != "") {
        int len = (int)num.size();
        for (int j = 0; j < 4 - len; j++) {
            num.insert(0, "0");
        }
        v.push_back(num);
        num = "";
    } 
    for (int i = 0; i < 8; i++) {
        cout << v[i] << ": "[i == 7];
    }
}