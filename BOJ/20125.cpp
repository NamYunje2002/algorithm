#include <bits/stdc++.h>
using namespace std;

int n, hx, hy;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string arr[1001];

int getLength(int x, int y, int idx) {
    int len = 1;
    while(1) {
        x += dx[idx];
        y += dy[idx];
        if(x < 0 || x >= n || y < 0 || y >= n) break;
        if(arr[x][y] != '*') break;
        len++;
    }
    return len;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1 ; j++) {
            if(arr[i][j] != '*') continue;
            int isHeart = 1;
            for(int k = 0; k < 4; k++) {
                if(arr[i+dx[k]][j+dy[k]] != '*') isHeart = 0;
            }
            if(isHeart) {
                hx = i;
                hy = j;
            }
        }
    }
    cout << hx+1 << " " << hy+1 << "\n";
    cout << getLength(hx, hy-1, 3) << " " << getLength(hx, hy+1, 1) << " " ;
    int wLen = getLength(hx+1, hy, 0);
    cout << wLen << " " << getLength(hx+wLen+1, hy-1, 0) << " " << getLength(hx+wLen+1, hy+1, 0);
}