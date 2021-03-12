#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(ll n) {
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++) {
        int temp = 0;
        if (n % i == 0) {
            temp = n/i + (i - 1) - 1;
        }
        else {
            temp = n/i + (i - 1);
        }
        if (temp < ans) {
            ans = temp;
        }
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}
