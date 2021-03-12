#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll solve(ll one[], ll two[], ll x, ll y, ll n) { 
    ll new_a = one[0];
    ll new_b = two[0];
    if (one[0] - one[1] > n) {
        new_a -= n;
        n = 0;
    }
    else {
        new_a = one[1];
        n -= (one[0] - one[1]);
    }
    if (n) {
        if (two[0] - two[1] > n) {
            new_b -= n;
            n = 0;
        }
        else {
            new_b = two[1];
        }
    }
    
    ll ans = new_a * new_b;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll min[2];
        ll bigger[2];
        if (b > a)  {
            min[0] = a;
            min[1] = x;
            bigger[0] = b;
            bigger[1] = y;
        }
        else {
            min[0] = b;
            min[1] = y;
            bigger[0] = a;
            bigger[1] = x;
        }

        ll ans_one = solve(min, bigger, x, y, n);
        ll ans_two = solve(bigger, min, x, y, n);
        if (ans_one > ans_two) {
            cout << ans_two << '\n';   
        }
        else {
            cout << ans_one << '\n';
        }
    }
}
