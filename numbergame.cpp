#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool prime(ll n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 3; i <= sqrt(n); i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve(ll n) {
    if (n == 1) { 
        cout << "FastestFinger" << '\n';
        return;
    }
    if (n == 2 || n % 2 != 0) {
        cout << "Ashishgup" << '\n';
        return;
    }

    // n is even here
    ll temp = n;
    while (n % 2 == 0) {
        n /= 2;
    }
    if (temp/n != 2 && n != 1) {
        cout << "Ashishgup" << '\n';
        return;
    }

    if (prime(n) || n == 1) {
        cout << "FastestFinger" << '\n';
        return;
    }   
    cout << "Ashishgup" << '\n';

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
