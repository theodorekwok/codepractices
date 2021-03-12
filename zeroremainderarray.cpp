#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[200000];


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            ll v;
            cin >> v;
            if (v % k == 0) a[i] = 0;
            else a[i] = (k - v%k);
        }
        sort(a, a + n);
        ll c = a[0];
        ll add = k;
        for (int i = 1; i < n; i++) {
            if (a[i] == c && a[i] != 0) {
                a[i] += add;
                add += k;
            }
            else {
                c = a[i];
                add = k;
            }
        }       
        sort(a, a + n);
        ll min = 0;
        min += a[0];
        bool all_zeros = (min == 0) ? true : false;
        for (int i = 1; i < n; i++) {
            min += a[i] - a[i - 1];        
            if (a[i] != 0) all_zeros = false;
        }
        min += 1;
        if (all_zeros) cout << 0 << '\n';
        else cout << min << '\n';
    }
}
