#include <bits/stdc++.h>

#define ll long long

using namespace std;


void solve(ll n, ll k) {
    k--;
    if (n % 2 == 0) {
        cout << (k%n)+1 << '\n';
        return;
    }
    //k++;
    int s = n/2;
    int steps = (k)/s;
    cout << (k + steps) % n + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        solve(n, k);
    }
}
