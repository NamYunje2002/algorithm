#include <bits/stdc++.h>
using namespace std;

int n, ans;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string arr[55];

void swap(int x, int y, int nx, int ny) {
    char tmp = arr[x][y];
    arr[x][y] = arr[nx][ny];
    arr[nx][ny] = tmp;
}

int find() {
    int rsl = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 4; k++) {
                int nx = i;
                int ny = j;
                int cnt = 0;
                while(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if(arr[i][j] != arr[nx][ny]) break;
                    cnt++;
                    nx += dx[k];
                    ny += dy[k];
                }
                rsl = max(rsl, cnt);
            }
        }
    }   
    return rsl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(arr[i][j] == arr[nx][ny]) continue;
                swap(i, j, nx, ny);
                int cnt = find();
                ans = max(ans, cnt);
                swap(i, j, nx, ny);
            }
        }
    }
    cout << ans;
}