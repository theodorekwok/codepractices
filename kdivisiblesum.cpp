#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll v = k;
        int add = (n % k == 0) ? 0 : 1;
        v *= ((n/k) + add);
        ll ans = v/n;
        if (v % n != 0) 
            ans += (v % n <= n) ? 1 : (v%n)/n + 1;
        cout << ans << '\n';
    }

}
