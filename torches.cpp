#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll x, ll y, ll k) {
    ll num_sticks_for_coal = y * k;
    ll total = num_sticks_for_coal + k;
    ll trades = (total - 1) % (x - 1) == 0 ? (total - 1)/(x - 1) : (total - 1)/(x - 1) + 1;
    cout << trades + k << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        solve(x, y, k);
    }
}
