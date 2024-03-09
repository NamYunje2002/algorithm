#include <bits/stdc++.h>
using namespace std;

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int year, cur, total;
string month, day, t;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> month >> day >> year >> t;
    int j;
    for(int i = 0; i < 12; i++) {
        j = i;
        if(month == "January" && i == 0) break;
        if(month == "February" && i == 1) break;
        if(month == "March" && i == 2) break;
        if(month == "April" && i == 3) break;
        if(month == "May" && i == 4) break;
        if(month == "June" && i == 5) break; 
        if(month == "July" && i == 6) break;
        if(month == "August" && i == 7) break;
        if(month == "September" && i == 8) break;
        if(month == "October" && i == 9) break;
        if(month == "November" && i == 10) break; 
        if(month == "December" && i == 11) break;
        cur += days[i];
    }

    total = 365 * 24;
    if(year%400==0 || (year%4==0 && year%100!=0)) {
        total += 24;
        if(j > 1) cur += 1;
    }
    total *= 60;

    cur += (stoi(day)-1);
    cur *= 24;
    if(stoi(t.substr(0, 2)) != 0) cur += stoi(t.substr(0, 2));
    cur *= 60;
    if(stoi(t.substr(3)) != 0) cur += stoi(t.substr(3));
    cout.precision(10);
    cout << (double)cur / (double)total * 100;
}   