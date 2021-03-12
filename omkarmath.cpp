#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool prime(ll n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i+=2) {
        if (n % i == 0) return false;
    }   
    return true;
}

void solve(ll n) {
    if (prime(n)) {
        cout << 1 << ' ' << n - 1 << '\n';
        return;
    }

    for (int i = 2; i <= sqrt(n); i+=1) {
        if (n % i == 0) {
            cout << n/i << ' ' << n - n/i << '\n';
            return;
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
}
