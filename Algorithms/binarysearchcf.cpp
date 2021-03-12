#include <bits/stdc++.h>

#define ll long long

using namespace std;


const ll MOD = 1000000000 + 7;


ll ncr(int n, int r) {
    vector<ll> row;
    row.push_back(1);
    ll np = n;
    if (r == 0) {
        return 1;
    }
    if (n == 0 && r != 0) {
        return 0;
    }
    for (ll i = 1; i <= r; i++) {
        row.push_back((row[i - 1]*(np)/i)%MOD);
        np--;
    }
    return row[r];
}

ll factorial(int x) {
    ll ans = 1;
    for (ll i = 1; i <= x; i++) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

void solve(int n, int x, int pos) {
    int greater = n - x;
    int smaller = x - 1;
    int l = 0;
    int r = n;
    int countsmaller = 0;
    int countbigger = 0;
    ll ans = 1;
    while (l < r) {
        int middle = (l + r)/2;
        if (pos > middle) {
           countsmaller++;
           ans = (ans * smaller) % MOD;
           smaller--;
        }
        if (pos < middle) {
            countbigger++;
            ans = (ans * greater) % MOD;
            greater--;
        }
        if (middle <= pos) {
            l = middle + 1;
        }
        else {
            r = middle;
        }
    } 
    ans = (ans * factorial(n - countbigger - countsmaller - 1)) % MOD;
    cout << ans << '\n';
}


int main() {
    int n, x, pos;
    cin >> n >> x >> pos;
    solve(n, x, pos);
}
