#include <bits/stdc++.h>

using namespace std;



void solve(int n) {
    int deg = n - 1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (deg % 2 == 0) {
            if (i < deg/2) {
                ans.push_back(1);
            }
            else {
                ans.push_back(-1);
            }
        }
        else {
            if (i < deg/2) {
                ans.push_back(1);
            }       
            else if (i == deg/2) {
                ans.push_back(0);
            }
            else {
                ans.push_back(-1);
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << ans[j] << ' ';
        }
    }
    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}
