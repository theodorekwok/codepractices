#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[200000];
ll ca[200000];


void solve(ll ca[], ll a[], int n) {
    sort(ca, ca + n);
    vector<ll> ps;
    ps.push_back(ca[0]);
    for (int i = 1; i < n; i++) {
        ps.push_back(ca[i] + ps[ps.size() - 1]);
    }
    ll num = 1;
    ll m = ca[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (ps[i] >= ca[i + 1]) {
            m = ca[i];
            num++;
        }
        else {
            break;
        }
    }
    cout << num << '\n';
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] >= m) cout << i << ' ';
    }    
    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ca[i] = a[i];
        }
        solve(a, ca, n);
    }

}
