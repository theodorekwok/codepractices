#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if (a + b < n + m) {
            cout << "No" << '\n';
        }
        else {
            ll s = min(a, b);
            if (m > s) {
                cout << "No" << '\n';
            }
            else {
                cout << "Yes" << '\n';
            }
        }
    }
}
