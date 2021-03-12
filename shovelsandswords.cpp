#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll a, ll b) {
    ll ans = 0;
    ll diff = abs(a - b);
    if (diff > min(a, b)) {
        ans = min(diff, min(a,b));
        cout << ans << '\n';
        return;
    }
    ans += diff;
    if (a < b) {
        a -= diff;
        b -= diff*2;
    }
    else {
        a -= 2*diff;
        b -= diff;
    }
    ans += (a/3)*2;
    if (a % 3 == 2) {
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
}
