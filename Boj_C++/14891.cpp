#include <bits/stdc++.h>
using namespace std;

int ans, chk[4];
string arr[4];

string Rotate(string s, int dic) {
	if (dic == 1) {
		char c = s[7];
		for (int i = 7; i > 0; i--) {
			s[i] = s[i - 1];
		}
		s[0] = c;
	}
	else {
		char c = s[0];
		for (int i = 0; i < 7; i++) {
			s[i] = s[i + 1];
		}
		s[7] = c;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> arr[i];
	int k; cin >> k;
	while (k--) {
		int num, dic; cin >> num >> dic;
		chk[num - 1] = 1;
		if (num == 1) {
			for (int i = 0; i < 3; i++) {
				if (arr[i][2] == arr[i + 1][6]) break;
				chk[i + 1] = 1;
			}
		}
		if (num == 2) {
			if (arr[0][2] != arr[1][6]) chk[0] = 1;
			for (int i = 1; i < 3; i++) {
				if (arr[i][2] == arr[i + 1][6]) break;
				chk[i + 1] = 1;
			}
		}
		if (num == 3) {
			if (arr[2][2] != arr[3][6]) chk[3] = 1;
			for (int i = 2; i > 0; i--) {
				if (arr[i][6] == arr[i - 1][2]) break;
				chk[i - 1] = 1;
			}
		}
		if (num == 4) {
			for (int i = 3; i > 0; i--) {
				if (arr[i][6] == arr[i - 1][2]) break;
				chk[i - 1] = 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (chk[i]) {
				if(num % 2 != i % 2)
					arr[i] = Rotate(arr[i], dic);
				else 
					arr[i] = Rotate(arr[i], dic * -1);
			}
		}	
		fill(chk, chk + 4, 0);
	}
	int sc = 1;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == '1') ans += sc;
		sc *= 2;
	}
	cout << ans;
}
