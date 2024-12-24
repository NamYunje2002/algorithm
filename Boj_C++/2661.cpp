// https://www.acmicpc.net/problem/2661

#include <iostream>
#include <string>

using namespace std;

int n, isFind;
string ans;

bool chk(string s) {
	for (int i = 1; i <= s.size() / 2; i++) 
		if (s.substr(s.size() - i, i) == s.substr(s.size() - i * 2, i))
			return false;
	return true;
}

void solve(string s) {
	if (isFind) return;
	if (s.size() == n) {
		ans = s;
		isFind = 1;
		return;
	}
	for (int i = 1; i <= 3; i++) 
		if (chk(s + to_string(i))) 
			solve(s + to_string(i));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	solve("1");
	cout << ans;
}
