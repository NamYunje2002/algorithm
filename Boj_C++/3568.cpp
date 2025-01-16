#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> v;
    while (1) {
        string s; cin >> s;
        v.push_back(s);
        if (s[(int)s.size() - 1] == ';') break;
    }
    for (int i = 1; i < (int)v.size(); i++) {
        string dType = v[0], name = "";
        for (int j = (int)v[i].size() - 2; j >= 0; j--) {
            if (('a' <= v[i][j] && v[i][j] <= 'z') || ('A' <= v[i][j] && v[i][j] <= 'Z')) {
                name += v[i][j];
            } else {
                if (v[i][j] == ']') v[i][j] = '[';
                else if (v[i][j] == '[') v[i][j] = ']';
                dType += v[i][j];
            }
        }
        reverse(name.begin(), name.end());
        cout << dType << " " << name << ";\n";
    }
}