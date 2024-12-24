#include <bits/stdc++.h>
using namespace std;

int n, ans, pre;
int A[500005], B[500005], tmp[500005];

int isSame() {
    int j = 0;
    for(int i = pre; i < n; i++) {
        if(A[i] != B[i]) {
            pre = max(0, i-1);
            return 0;
        }
    }
    return 1;
}

void mergeSort(int low, int high) {
    if(low >= high) return;
    int mid = (low+high)/2;
    mergeSort(low, mid);
    mergeSort(mid+1, high);
    
    int i = low, j = mid+1;
    int cnt = 0;
    while(i <= mid && j <= high) {
        if(A[i] <= A[j]) tmp[cnt++] = A[i++];
        else tmp[cnt++] = A[j++];
    }
    while(i <= mid) tmp[cnt++] = A[i++];
    while(j <= high) tmp[cnt++] = A[j++];
    i = low, cnt = 0;
    while(i <= high) {
        if(A[i] != tmp[cnt]) {
            if(i < pre) {
                cout << 0;
                exit(0);
            }
            A[i++] = tmp[cnt++];
            if(isSame()) {
                cout << 1;
                exit(0);
            }
        }
        else {
            A[i++] = tmp[cnt++];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    if(isSame()) {
        cout << 1;
        exit(0);
    }
    mergeSort(0, n-1);
    cout << ans;
}