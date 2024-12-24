#include <bits/stdc++.h>
using namespace std;

set<string> st;

int cmp(string s1, string s2) {
	vector<string> v1;
	vector<string> v2;
	string s = "";
	for (int i = 0; i < (int)s1.size(); i++) {
		if (s1[i] == '\\') {
			v1.push_back(s);
			s = "";
		} else {
			s += s1[i];
		}
	}
	v1.push_back(s);
	s = "";
	for (int i = 0; i < (int)s2.size(); i++) {
		if (s2[i] == '\\') {
			v2.push_back(s);
			s = "";
		} else {
			s += s2[i];
		}
	}
	v2.push_back(s);

	for (int i = 0; i < (int)v1.size() && i < v2.size(); i++) {
		if (v1[i] == v2[i]) continue;
		return v1[i] < v2[i];
	}

	return v1.size() < v2.size();
}

void checkPath(string path, string total, int cnt) {
	if (st.find(total) == st.end()) {
		for (int k = 0; k < cnt; k++) cout << " ";
		cout << path << "\n";
		st.insert(total);
	}
	path = "";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n; 
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < (int)v.size(); i++) {
		string cur = v[i];
		int cnt = 0;
		string path = "", total = "";
		for (int j = 0; j < (int)cur.size(); j++) {
			total += cur[j];
			if (cur[j] == '\\') {
				checkPath(path, total, cnt);
				path = "";
				cnt++;
			} else {
				path += cur[j];
			}
		}
		total += "\\";
		checkPath(path, total, cnt);
	}
}