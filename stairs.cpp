#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll x) {
    ll cells = 0;
    ll add = 1;
    ll factor = 2;
    ll ans = 0;
    while (cells <= x) {
        cells += (ll) ((add + 1) * double (add/2.0));
        //cout << "Cells " << cells << '\n';
        
        add += factor;
        factor *= 2; 
        if (cells <= x) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        solve(x);
    }
    return 0;
}
