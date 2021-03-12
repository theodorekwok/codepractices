#include <bits/stdc++.h>

#define ll long long

using namespace std;


bool isprime(ll prime) {
    if (prime == 2) return true;
    if (prime % 2 == 0) return false;
    for (ll i = 3; i <= sqrt(prime); i++) {
        if (prime % i == 0) return false;
    }
    return true;
}

void solve(ll p, ll q) {
    if (p % q != 0) {
        cout << p << '\n';
        return;
    }
    ll sf = 2;
    bool prime = true;
    for (int i = 2; i <= sqrt(q); i++) {
        if (q % i == 0) {
            sf = i;
            prime = false;
            break;
        }
    }
    if (prime) {
        while (p % q == 0) p /= q;
        cout << p << '\n';
        return;
    }
    vector<vector<ll>> factor_q;
    ll temp = q;
    ll counter = 0;
    while (temp % 2 == 0) {
        temp /= 2;
        counter++;
    }
    if (counter) factor_q.push_back({2, counter});

    for (int i = 3; i <= sqrt(temp); i+=2)  {
        ll count = 0;
        while (temp % i == 0) {
            temp /= i;
            count++;
        }
        // cout << "factor " << ' ' << i << ' ' << "Count " << count << '\n';
        if (count) factor_q.push_back({i, count});
    }
    if (temp > 2) factor_q.push_back({temp, 1});
    ll ans = 0;
    for (int i = 0; i < factor_q.size(); i++) {
        // cout << factor_q[i][0] << ' ' << factor_q[i][1] << '\n';
        ll v = p;
        while (v % factor_q[i][0] == 0) {
            v /= factor_q[i][0];
            //cout << v << '\n';
            if (v % q != 0) {
                ans = max(ans, v);
                break;
            }
        }

    }
    cout << ans << '\n';

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        solve(p, q);
    }
}
