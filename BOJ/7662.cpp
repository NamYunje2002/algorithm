#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int heapSize;
ll mmHeap[1000005];
int s1[15], s2[15];

int isMinLevel(int level) {
    return (level % 2 == 1);
}

void swap(ll *a, ll *b) {
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}

void upHeap(int idx, int level) {
    if(idx/2 < 1) return;
    if(isMinLevel(level)) {
        if(mmHeap[idx] > mmHeap[idx/2]) {
            swap(&mmHeap[idx], &mmHeap[idx/2]);
            level--;
            idx /= 2;
        }
    } else {
        if(mmHeap[idx] < mmHeap[idx/2]) {
            swap(&mmHeap[idx], &mmHeap[idx/2]);
            level--;
            idx /= 2;
        }
    }
    while(idx/4 >= 1) {
        int chk = 0;
        if(isMinLevel(level)) {
            if(mmHeap[idx] < mmHeap[idx/4]) {
                swap(&mmHeap[idx], &mmHeap[idx/4]);
                idx /= 4;
            } else chk = 1;
        } else {
            if(mmHeap[idx] > mmHeap[idx/4]) {
                swap(&mmHeap[idx], &mmHeap[idx/4]);
                idx /= 4;
            } else chk = 1;
        }
        if(chk) break;
    }
}

void downHeap(int idx, int level) {
    while(idx*2 <= heapSize) {
        int chk = 0;
        if(isMinLevel(level)) {
            int mnIdx = idx;
            for(int i = idx; i <= idx*4+3 && heapSize; i++) {
                if(mmHeap[i] < mmHeap[mnIdx]) mnIdx = i;
            }
            if(2*idx <= mnIdx <= 2*idx+1) {
                swap(mmHeap[idx], mmHeap[mnIdx]);
                idx = mnIdx;
                level += 1;
            }
            else if(idx*4 <= mnIdx <= idx*4+3) {
                swap(mmHeap[idx], mmHeap[mnIdx]);
                idx = mnIdx;
                if(mmHeap[idx] > mmHeap[idx/2]) swap(mmHeap[idx], mmHeap[idx/2]);
                level += 2;
            } else chk = 1;
        } else {
            int mxIdx = idx;
            for(int i = idx; i <= (idx*2+1)*2+1 && heapSize; i++) {
                if(mmHeap[i] > mmHeap[mxIdx]) mxIdx = i;
            }
            if(2*idx <= mxIdx <= 2*idx+1) {
                swap(mmHeap[idx], mmHeap[mxIdx]);
                idx = mxIdx;
                level += 1;
            }
            else if(idx*4 <= mxIdx <= (idx*2+1)*2+1) {
                swap(mmHeap[idx], mmHeap[mxIdx]);
                idx = mxIdx;
                if(mmHeap[idx] < mmHeap[idx/2]) swap(mmHeap[idx], mmHeap[idx/2]);
                level += 2;
            } else chk = 1;
        }
        if(chk) break;
    }
}

void insertHeap(ll num) {
    mmHeap[++heapSize] = num;
    int level = 1;
    for(int i = 14; i >= 0; i--) {
        if(heapSize > s2[i]) {
            level = i+2;
            break;
        }
    }
    upHeap(heapSize, level);
}

void removeMn() {
    if(heapSize == 0) return;
    mmHeap[1] = mmHeap[heapSize];
    mmHeap[heapSize--] = 0;
    downHeap(1, 1);
}

void removeMx() {
    if(heapSize == 1) {
        removeMn();
    } else if(heapSize >= 2) {
        int mxIdx = 2;
        if(heapSize > 2) if(mmHeap[3] > mmHeap[2]) mxIdx = 3;
        mmHeap[mxIdx] = mmHeap[heapSize];
        mmHeap[heapSize--] = 0;
        downHeap(mxIdx, 1); 
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    s1[0] = s2[0] = 1;
    for(int i = 1; i < 15; i++) {
        s1[i] = s1[i-1]*2;
        s2[i] = s1[i-1]*2+s2[i-1];
    }
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        while(k--) {
            string s; ll n;
            cin >> s >> n;
            if(s == "I") {
                insertHeap(n);
            } else {
                if(n == 1) removeMx();
                else removeMn();
            }
        }  
        if(heapSize == 0) cout << "EMPTY\n";
        else {
            int mxIdx = 1;
            if(heapSize >= 2)  {
                mxIdx = 2;
                if(heapSize > 2) if(mmHeap[3] > mmHeap[2]) mxIdx = 3;
            }
            cout << mmHeap[mxIdx] << ' ' << mmHeap[1] << '\n';
        }
        fill(mmHeap, mmHeap+1000005, 0);
        heapSize = 0;
    }
}