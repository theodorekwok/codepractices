#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, z;
        cin >> x >> y >> z;
        ll x_two, y_two , z_two;
        cin >> x_two >> y_two >> z_two;
        ll ans = min(z, y_two) * 2;
        z -= min(z, y_two);
        y_two -= min(z, y_two);
        ll penalty = (z_two < z + x) ? 0 : (z_two - z - x)*2;
        ans -= penalty;
        cout << ans << '\n';
    }
}
