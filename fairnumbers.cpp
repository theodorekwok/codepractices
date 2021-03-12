#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll n) {
    
    while (true) {
        ll temp = n;
        bool divisible = true;
        while (temp) {
            int last_digit = temp % 10;
            if (last_digit != 0 && n % last_digit != 0) {
                divisible = false;
                break;
            }
            temp /= 10;
        }
        if (divisible) {
            cout << n << '\n';
            return;
        }
        n++;
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
