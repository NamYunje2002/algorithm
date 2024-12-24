#include <bits/stdc++.h>
using namespace std;

int cnt;
stack<char> st;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] ==')') {
            while(st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }else if(s[i] == '(') {
            st.push(s[i]);
        }else if(s[i] == '*' || s[i] == '/') {
            if(!st.empty()) 
            while(!st.empty()) {
                if(st.top() == '+' || st.top() == '-' || st.top() == '(') break;
                else {
                    cout << st.top();
                    st.pop();
                }
            }   
            st.push(s[i]);
        } else if(s[i] == '+' || s[i] == '-') {
            if(!st.empty()) {
                while(!st.empty()) {
                    if(st.top() == '(') break;
                    else {
                        cout << st.top();
                        st.pop();
                    }
                }   
            }
            st.push(s[i]);
        } else cout << s[i];
    }
    while(!st.empty()) {
        if(st.top() != '(') cout << st.top();
        st.pop();
    }
}