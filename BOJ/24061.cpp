#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
int ans = -1;

void print(int *arr, int *tmpArr, int l, int cnt2) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(l <= i && i < l+cnt2) cout << tmpArr[j++] << ' ';
        else cout << arr[i] << ' ';
    }
    ans = 0;
}

void merge(int *arr, int l, int m, int r) {
    int *tmpArr = (int*)malloc((r-l+1) * sizeof(int));
    int i = l, j = m+1, t = 0, cnt2 = 0;
    while(i <= m && j <= r) {
        cnt++; cnt2++;
        if(arr[i] <= arr[j]) tmpArr[t++] = arr[i++];
        else tmpArr[t++] = arr[j++];
        if(cnt == k) print(arr, tmpArr, l, cnt2);
    }   
    while(i <= m) {
        tmpArr[t++] = arr[i++];
        cnt++; cnt2++;
        if(cnt == k) print(arr, tmpArr, l, cnt2);
    }
    while(j <= r) {
        tmpArr[t++] = arr[j++];
        cnt++; cnt2++;
        if(cnt == k) print(arr, tmpArr, l, cnt2);
    }
    i = l, t = 0;
    while(i <= r) arr[i++] = tmpArr[t++];
}

void mergeSort(int *arr, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, 0, n-1);
    if(ans == -1) cout << ans;
}