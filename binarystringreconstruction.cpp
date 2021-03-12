#include <bits/stdc++.h>

using namespace std;

void printans(vector<int>& w) {
    for (int i = 0; i < w.size(); i++) {
        cout << w[i];
    }
    cout << '\n';
}

void solve(string s, int x) {
    int n = s.size();
    vector<int> w(n, 1);
    // (i > x & w[i-x] == 1) | (i + x <= n - 1 & w[i+x] == 1) -> s[i] = 1
    // (i <= x | w[i-x] == 0) & (i + x > n - 1 | w[i+x] == 0) -> s[i] = 0
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (i >= x) {
                w[i-x] = 0;
            }
            if (i + x <= n - 1) {
                w[i+x] = 0;
            }
        }
    }
    
    // printans(w);
    for (int i = 0; i < n; i++) {
        char rightsvalue = '0';
        if ((i >= x && w[i-x] == 1) || (i + x <= n - 1 && w[i+x] == 1)) {
            rightsvalue = '1';
        }
        if (s[i] != rightsvalue) {
            cout << -1 << '\n';
            return;
        }
    }
    printans(w);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        solve(s, x);
    }
}
