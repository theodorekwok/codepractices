#include <bits/stdc++.h>

#define ll long long

using namespace std;


void solve(ll n) {
    ll ans = 0;
    int upperbound = (int) sqrt(2*n - 1);
    ans += (upperbound/2);
    ans += (upperbound % 2 == 0)? 0 : 1;
    cout << ans - 1 << '\n';
}   


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
}
