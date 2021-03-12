#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[100001];


int main() {
    ll n, q, k;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ll ans = (a[l] - 1) + (k - a[r]) + (a[r] - a[l] - r + l)*2;
        cout << ans << '\n';
    }
}
