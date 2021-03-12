#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll x[1000], y[1000];


void solve(ll x[], ll y[], int n) {
    sort(x, x + n);
    sort(y, y + n);
    ll x_median = x[n/2];
    ll x_second_median = x[n/2 - 1];
    ll y_median = y[n/2];
    ll y_second_median = y[n/2 - 1];
    if (n % 2 == 0) {
        cout << (x_median - x_second_median + 1)*(y_median - y_second_median + 1) << '\n';
    }
    else {
        cout << 1 << '\n';
    }   
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        solve(x, y, n);
    }
}
