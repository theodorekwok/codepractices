#include <bits/stdc++.h>

#define ll long long

using namespace std;


void solve(vector<int> store, ll n, ll s) {
    int power = store.size() - 1;
    int r = store.size() - 1;
    int sum = 0;
    if (store[r] >= s) {
        ll ans = 0;
        ans += 1;
        for (int i = 0; i <= power; i++) {
            ans *= 10;
        }
        cout << ans - n << '\n';
        return;
    }
    ll ans = 0;
    vector<int> digits;
    while (sum < s) {
        digits.push_back(store[r]);
        sum += store[r];
        r--;
    }
    ll f = 1;
    digits[digits.size() - 2]++;
    for (int i = digits.size() - 2; i >= 0; i--) {
        ans += digits[i] * f;
        f *= 10;
    }
    for (int i = 0; i < power - digits.size() + 2; i++) {
        ans *= 10;
    }
    cout << ans - n << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, s;
        cin >> n >> s;
        int sum = 0;
        ll temp = n;
        vector<int> store;
        while (temp) {
            store.push_back(temp % 10);
            sum += temp % 10;
            temp /= 10;
        }
        if (sum <= s) {
            cout << 0 << '\n';
        }
        else {
            solve(store, n, s);
        }
    }
}
