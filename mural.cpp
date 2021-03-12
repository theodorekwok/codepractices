#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[5000000];


void solve(ll a[], int N) {
    ll r = (N % 2 == 0) ? N/2 : N/2 + 1;
    ll l = 0;
    ll ans = 0;
    for (int i = l; i < r; i++) {
        ans += a[i];
    }
    ll temp = ans;
    for (int i = r; i < N; i++) {    
        temp += (a[i] - a[i - r]);
        ans = max(temp, ans);
    }
    cout << ans << '\n';
}


int main() {
    int T;
    cin >> T;
    ll counter = 1;
    while (T--) {
        int N;
        cin >> N;
        
        string v;
        cin >> v;
        for (int i = 0; i < N; i++) {
            a[i] = v[i] - '0';
        }

        cout << "Case #" << counter << ": ";
        solve(a, N);
        counter++;
    }
}
