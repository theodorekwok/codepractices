#include <bits/stdc++.h>

using namespace std;

int a[200000];


void solve(int a[], int n) {
    if (n == 1 || n == 2) {
        int ans = (a[0] == 1) ? 1 : 0;
        cout << ans << '\n';
        return;
    }
    vector<vector<int>> dp;
    if (a[n - 1] == 1) {
        dp.push_back({1, 0});
    }
    else {
        dp.push_back({0, 0});
    }
    if (a[n - 2] == 1) {
        dp.push_back({1, 0});
    }
    else {
        dp.push_back({0, 0});
    }
    for (int i = n - 3; i >= 0; i--) {
        int v = a[i];
        if (i == 0) {
            int ans = min(dp[dp.size() - 1][0], dp[dp.size() - 1][1]) + v;
            cout << ans << '\n';
        }
        dp.push_back({min(dp[dp.size() - 1][0], dp[dp.size() - 1][1]) + v, min(dp[dp.size() - 1][0], dp[dp.size() - 2][0])});
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, n);
    }
}
