#include <bits/stdc++.h>

using namespace std;

int a[50];

void solve(int a[], int n) {
    sort(a, a + n);
    int ans = 0;
    for (int i = a[0]*2; i <= a[n - 1]*2; i++) {
        int s = i;
        int f = 0;
        int b = n - 1;
        int pairs = 0;
        while (f < b) {
            if (a[f] + a[b] == s) {
                pairs++;
                f++;
                b--;
            }
            else if (a[f] + a[b] > s) {
                b--;
            }
            else {
                f++;
            }
        }
        if (pairs > ans) {
            ans = pairs;
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
