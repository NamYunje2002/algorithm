#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

const ll MX = 1000000000;

pair<string, ll> cmdArr[100005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1) {
        int cmdCnt = 0;
        while (1) {
            cin >> cmdArr[cmdCnt++].X;
            if (cmdArr[cmdCnt - 1].X == "END" || cmdArr[cmdCnt - 1].X == "QUIT") break;
            if (cmdArr[cmdCnt - 1].X == "NUM") cin >> cmdArr[cmdCnt - 1].Y;
        }
        if (cmdArr[0].X == "QUIT") break;
        int n; cin >> n;
        while (n--) {
            ll num; cin >> num;
            int error = 0;
            stack<ll> st;
            st.push(num);
            for (int i = 0; i < cmdCnt; i++) {
                string curCmd = cmdArr[i].X;
                if (curCmd == "NUM") {
                    st.push(cmdArr[i].Y);
                } else if (curCmd == "POP") {
                    if (st.empty()) {
                        error = 1;
                        break;
                    } 
                    st.pop();
                } else if (curCmd == "INV") {
                    if (st.empty()) {
                        error = 1;
                        break;
                    } 
                    ll topNum = st.top();
                    st.pop();
                    st.push(topNum * -1);
                } else if (curCmd == "DUP") {
                    if (st.empty()) {
                        error = 1;
                        break;
                    } 
                    st.push(st.top());
                } else if (curCmd == "SWP") {
                    if (st.size() < 2) {
                        error = 1;
                        break;
                    } 
                    ll firstNum = st.top(); st.pop();
                    ll secondNum = st.top(); st.pop();
                    st.push(firstNum); 
                    st.push(secondNum);
                } else if (curCmd == "ADD") {
                    if (st.size() < 2) {
                        error = 1;
                        break;
                    } 
                    ll firstNum = st.top(); st.pop();
                    ll secondNum = st.top(); st.pop();
                    ll ret = firstNum + secondNum;
                    if (abs(ret) > MX) {
                        error = 1;
                        break;
                    }
                    st.push(ret);
                } else if (curCmd == "SUB") {
                    if (st.size() < 2) {
                        error = 1;
                        break;
                    } 
                    ll firstNum = st.top(); st.pop();
                    ll secondNum = st.top(); st.pop();
                    ll ret = secondNum - firstNum;
                    if (abs(ret) > MX) {
                        error = 1;
                        break;
                    }
                    st.push(ret);
                } else if (curCmd == "MUL") {
                    if (st.size() < 2) {
                        error = 1;
                        break;
                    } 
                    ll firstNum = st.top(); st.pop();
                    ll secondNum = st.top(); st.pop();
                    ll ret = firstNum * secondNum;
                    if (abs(ret) > MX) {
                        error = 1;
                        break;
                    }
                    st.push(firstNum * secondNum);
                } else if (curCmd == "DIV") {
                    if (st.size() < 2) {
                        error = 1;
                        break;
                    } 
                    ll firstNum = st.top(); st.pop();
                    ll secondNum = st.top(); st.pop();
                    if (firstNum == 0) {
                        error = 1;
                        break;
                    }
                    ll ret = abs(secondNum) / abs(firstNum);
                    if (abs(ret) > MX) {
                        error = 1;
                        break;
                    }
                    if ((firstNum < 0 && secondNum > 0) || (firstNum > 0 && secondNum < 0)) ret *= -1;
                    st.push(ret);
                } else if (curCmd == "MOD") {
                    if (st.size() < 2) {
                        error = 1;
                        break;
                    } 
                    ll firstNum = st.top(); st.pop();
                    ll secondNum = st.top(); st.pop();
                    if (firstNum == 0) {
                        error = 1;
                        break;
                    }
                    ll ret = abs(secondNum) % abs(firstNum);
                    if (abs(ret) > MX) {
                        error = 1;
                        break;
                    }
                    if (secondNum < 0) ret *= -1;
                    st.push(ret);
                } 
            }
            if (st.size() != 1) error = 1;
            if (error) cout << "ERROR\n";
            else cout << st.top() << "\n";
        }
        cout << "\n";
    }
}