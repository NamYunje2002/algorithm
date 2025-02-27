#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cin.ignore();
	for (int k = 1; k <= n; k++) {
		int ans = 3;
		int arr[26];
		for (int i = 0; i < 26; i++) arr[i] = 0;
		string s;
		getline(cin, s);
		for (int i = 0; i < (int)s.size(); i++) {
			if ('a' <= s[i] && s[i] <= 'z') arr[s[i] - 'a']++;
			else if ('A' <= s[i] && s[i] <= 'Z') arr[s[i] - 'A']++;
		}
		for (int i = 0; i < 26; i++) ans = min(ans, arr[i]);
		cout << "Case " << k << ": ";
		if (ans == 0) cout << "Not a pangram\n";
		else if (ans == 1) cout << "Pangram!\n";
		else if (ans == 2) cout << "Double pangram!!\n";
		else if (ans == 3) cout << "Triple pangram!!!\n";
	}
}