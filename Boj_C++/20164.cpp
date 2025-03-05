#include <bits/stdc++.h>
using namespace std;

int maxAns = 0, minAns = 0x7f7f7f7f;
map<string, int> mp;

void solve(string s, int cnt) {
	for (int i = 0; i < (int)s.size(); i++) {
		if ((s[i] - '0') % 2 == 1) cnt++;
	}
	if ((int)s.size() == 1) {
		maxAns = max(maxAns, cnt);
		minAns = min(minAns, cnt);
	} else if ((int)s.size() == 2) {
		solve(to_string((s[0] - '0') + (s[1] - '0')), cnt);
	} else {
		for (int i = 1; i < (int)s.size() - 1; i++) {
			for (int j = i + 1; j < (int)s.size(); j++) {
				string nxt = to_string(stoi(s.substr(0, i)) + stoi(s.substr(i, j - i)) + stoi(s.substr(j)));
				solve(nxt, cnt);
			}
		}
	}
}

int main() {
	string s; cin >> s;
	solve(s, 0);
	cout << minAns << " " << maxAns;
}