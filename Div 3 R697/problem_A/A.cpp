#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long


void solve(ll n) {
    if (n % 2 != 0) {
        cout << "YES" << '\n';
        return;
    }

    while (n % 2 == 0) {
        n /= 2;
        if (n % 2 != 0 && n != 1) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }    
    return 0;

}
