#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll p[100];


void solve(ll p[], int n, int k) {
    vector<ll> ps;
    ps.push_back(p[0]);
    for (int i = 1; i < n; i++) {
        ps.push_back(ps[i-1] + p[i]);
    }
    ll ans = 0;
    for (int i = 1; i < ps.size(); i++) {
        ll v = p[i]*100;
        if (v % k == 0) {
            v /= k;
        }
        else {
            v /= k;
            v++;
        }
        ll boundary = (ps[i-1]+ans);
        if (v - boundary > 0) {
            ans += v - boundary;
        }
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        solve(p, n, k);
    }
}
