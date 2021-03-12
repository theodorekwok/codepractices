#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll n, ll p, ll k, string s, ll x, ll y) {
    vector<ll> arr(k, 0);
    ll min = INT_MAX;
    int index = k - 1;
    for (int i = n - p; i >= 0; i--) {
        if (index == -1) {
            index = k - 1;
        }
        if (i + p + k > s.size()) {
            arr[index] = (i)*y;
        }
        else {
            arr[index] -= y*k;
            
        }
        arr[index] += (s[i + p - 1] == '0') ? x : 0;
        if (arr[index] < min) {
            min = arr[index];
        }
        // cout << arr[index] << ' ' << index << '\n';
        index--;
    }

    cout << min << '\n';


}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, p, k;
        cin >> n >> p >> k;

        string s;
        cin >> s;
        ll x, y;
        cin >> x >> y;
        solve(n, p, k, s, x, y);
    }
}
