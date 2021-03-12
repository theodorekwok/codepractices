#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(ll N) {
    ll ans = 0;
    while (N > 0) {
        if ((N % 2 == 0 && N % 4 != 0) || N == 4) {
            ans += N / 2;
            N /= 2;
        }
        else {
            ans += 1;
            N -= 1;
        }

        if ((N % 2 == 0 && N % 4 != 0) || N == 4) {
            N /= 2;
        }
        else {
            N -= 1;
        }
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll N;
        cin >> N;
        solve(N);
    }
}
