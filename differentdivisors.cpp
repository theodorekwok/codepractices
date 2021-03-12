#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool prime(int start) {
    if (start == 2) {
        return true;
    }
    if (start % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(start); i++) {
        if (start % i == 0) {
            return false;
        }
    }
    return true;
}


void solve(int d) {
    ll ans = 1;
    int start = 1 + d;
    for (int i = 0; i < 2; i++) {
        while (!prime(start)) {
            start++;
        }
        ans *= start;
        start += d;        
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        solve(d);
    }
}
