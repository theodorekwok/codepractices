#include <bits/stdc++.h>

using namespace std;

int arr[200000];

void solve(string s, int n) {
    int k = 1;
    stack<int> szero;
    stack<int> sone;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (sone.empty()) {
                arr[i] = k;
                szero.push(k);
                k++;
            }
            else {
                int team = sone.top();
                arr[i] = team;
                sone.pop();
                szero.push(team);
            }
        }
        else {
            if (szero.empty()) {
                arr[i] = k;
                sone.push(k);
                k++;
            }
            else {
                int team = szero.top();
                arr[i] = team;
                szero.pop();
                sone.push(team);
            }
        }       
    }

    int spaces = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > spaces) spaces = arr[i];
    }       
    cout << spaces << '\n';
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
}
