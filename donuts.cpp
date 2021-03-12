#include <bits/stdc++.h>

#define ll long long

using namespace std;


void solve(ll a, ll b, ll c) {
    ll one = -1;
    ll two = -1;
    ll cost_a = a*b;
    if (cost_a > c) {
        two = b;
    }

    if (a < c) one = 1;
    cout << one << ' ' << two << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
}
