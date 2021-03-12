#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a[100000];

void solve(ll a[], int n) {
    int b = 0;
    int f = 1;
    while (f < n) {
        if (a[b] > 0 && a[f] < 0) {
            if (a[b] > abs(a[f])) {
                a[b] -= abs(a[f]);
                a[f] = 0;
                f++;
            }
            else {
                a[f] += a[b];
                a[b] = 0;
                b++;
            }
        }
        else {
            if (b == f) {
                b++;
                f += 2;
            }
            else {
                if (a[b] <= 0) {
                    b++;
                }
                if (a[f] >= 0) {
                    f++;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {  
        if (a[i] > 0) {
            ans += a[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }   
        solve(a, n);
    }
}
