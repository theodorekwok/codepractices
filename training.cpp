#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[100000];

void solve(ll a[], int N, int P) {
    ll ans = INT_MAX;
    ll ps = 0;
    for (int i = 0; i < P; i++) {
        ps += a[i];
    }
    ans = min(ans, a[P - 1]*P - ps);
    for (int i = P; i < N; i++) {
        ps -= a[i - P];
        ps += a[i];
        ans = min(ans, a[i]*P - ps);
    }
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    int counter = 1;
    while (T--) {
        int N, P;
        cin >> N >> P;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a + N);
        cout << "Case #" << counter << ": ";
        solve(a, N, P);
        counter++;
    }
}
