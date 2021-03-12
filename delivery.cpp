#include <bits/stdc++.h>

#define ll long long

using namespace std;


void solve(vector<vector<ll>> d) {
    sort(d.begin(), d.end(), [](const vector<ll> &a, const vector<ll> &b) {
        return a[0] > b[0];
    });

    ll max_time = d[0][0];
    ll self_time = d[0][1];

    if (self_time > max_time) {
        cout << max_time << '\n';
        return;
    }

    ll ans = max_time;
    
    for (int i = 1; i < d.size(); i++) {
        ll temp = max(d[i][0], self_time);
        if (temp < ans) {
            ans = temp;
        }
        self_time += d[i][1];
    }
    if (self_time < ans) {
        cout << self_time << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<ll>> d(n);
        for (int i = 0; i < n; i++) {
            ll time;
            cin >> time;
            d[i].push_back(time);
        }
        for (int i = 0; i < n; i++) {
            ll s_time;
            cin >> s_time;
            d[i].push_back(s_time);
        }
        solve(d);
    }
    return 0;
}
