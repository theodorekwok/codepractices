#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll power(ll a, ll i) {
    ll r = 0;
    while (a) {
        a /= i;
        r++;
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans = LLONG_MAX;
        ll add = 0;
        if (b == 1) {
            b++;
            add = 1;
        }
        if (a == 1 || a < b) {
            ans = 1;
        }
        else {
            if (sqrt(a) == b) ans = 3;
            else if (b > sqrt(a)) ans = 2;
        }
        for (ll i = b; i <= ceil(sqrt(a)); i++) {
            ll rounds = power(a, i);
            //cout << "in loop " << rounds << '\n';
            rounds += (i - b);
            // cout << "in loop " << rounds << '\n';
            if (rounds < ans) {
                ans = rounds;
                // cout << rounds << '\n';
            }
        }
        cout << ans + add << '\n';
    }
}

