#include <bits/stdc++.h>

#define ll long long

using namespace std;

int a[200000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i <= n - 3; i++) {
            int mv = a[i] + 2;
            int index;
            int *pindex = &index;
            pindex = upper_bound(a, a + n, mv);
            //cout << mv << ' ' << pindex - a << '\n';
            ll num = pindex - a;
            ans += (ll) (num - i - 1)*(num - i - 2)/2;
        } 
        cout << ans << '\n';
    }
}
