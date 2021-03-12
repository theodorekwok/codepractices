#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, r;
        cin >> n >> r;
        ll ans = 0;
        if (n > r) {
            ans = r*(r+1)/2;
        }
        else {
            ans = (n - 1)*(n)/2 + 1;
        }
        cout << ans << '\n';
    }
}
