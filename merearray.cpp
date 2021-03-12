#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[100000];
ll b[100000];
void solve(ll a[], ll b[], int n) {
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && b[i] % a[0] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        solve(a, b, n);
    }
}

