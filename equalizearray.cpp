#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[200000];


void solve(ll a[], int n) {
    vector<ll> freq;
    int f = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            f++;
        }
        else {
            freq.push_back(f);
            f = 1;
        }
    }
    freq.push_back(f);
    sort(freq.begin(), freq.end());
    // for (int i = 0; i < freq.size(); i++) cout << freq[i] << '\n';
    vector<ll> ps;
    ps.push_back(freq[0]);
    for (int i = 1; i < freq.size(); i++) {
        ps.push_back(freq[i] + ps[i - 1]);
    }
    ll ans = 0;
    if (ps.size() >= 2) {
        ans = ps[ps.size() - 2];
    }
    int span = 1;
    int diff = 0;
    for (int i = ps.size() - 2; i >= 0; i--) {
        ll d = freq[i + 1] - freq[i];
        diff += d*span;
        ll val = diff;
        if (i - 1 >= 0) {
            val += ps[i - 1];
        }
        // cout << ans << ' ' << val << '\n';
        ans = min(ans, val);
        span++;
    }
    cout << ans << '\n';
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
        sort(a, a + n);
        solve(a, n);
    }
}
