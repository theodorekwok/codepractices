#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[200000];

int main() {
    int n;
    cin >> n;
    // first is value, second is index
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<ll,ll>cnts;
    cnts[0]++;
    ll ans = 0;
    ll ps = 0;
    for (int i = 0; i < n; i++) {
        ps += a[i];
        if (cnts[ps]) {
            ans++;
            cnts.clear();
            cnts[0]++;
            ps = a[i];
        }
        cnts[ps]++;
    }
    
    cout << ans << '\n';

}
