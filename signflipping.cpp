#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[99];

void solve(ll *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) a[i] *= -1;
    }
    for (int i = 1; i < n - 1; i += 2) {
        if ((a[i + 1] > a[i] && a[i] > a[i - 1]) || (a[i + 1] < a[i] && a[i] < a[i - 1])) {
            a[i] *= -1;
        }
    }
    for (int ele = 0; ele < n; ele++) {
        cout << a[ele] << ' ';
    }
    cout << '\n';

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        solve(a, n);
    } 
}
