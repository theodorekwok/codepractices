#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(vector<ll> arr, ll w) {
    ll lower = ceil(w/2.0);
    vector<ll> ans;
    ll cur = 0;
    vector<vector<ll>> ar;
    for (int i = 0; i < arr.size(); i++) {
        ar.push_back({i + 1, arr[i]});
    }
    sort(ar.begin(), ar.end(), [](const vector<ll> &a, const vector<ll> &b) {
        return a[1] < b[1];
    });
    for (int i = ar.size() - 1; i >= 0; i--) {
        if (cur + ar[i][1] <= w) {
            ans.push_back(ar[i][0]);
            cur += ar[i][1];
        }
    }

    if (cur >= lower && ans.size() != 0) {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, w;
        cin >> n >> w;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, w);
    }
    return 0;
}
