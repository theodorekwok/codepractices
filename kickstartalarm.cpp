#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[1000000];

// store the summation of powers
ll s[1000001];

const ll MOD = 1000000007;

ll power(int K, int r) {
    ll ans = 1;
    while (K != 0) {
        if (K % 2 == 1) ans = ans * r % MOD;
        r = r * r % MOD;
        K /= 2;
    }
    return ans;
}

void solve(ll a[], ll s[], int N, int K) {
    ll ans = 0;
    ll sum = 0;
    int factor = N;
    for (int i = 1; i <= N; i++) {
        sum += s[i];
        sum %= MOD;
        ll addition = ((sum*factor) % MOD * a[i - 1] % MOD) % MOD;
        ans += addition; 
        ans %= MOD;
        factor--;
    }
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    int counter = 1;
    while (T--) {
        int N, K, x, y, C, D, E1, E2, F;
        cin >> N >> K >> x >> y >> C >> D >> E1 >> E2 >> F;
        a[0] = (x + y) % F;
        for (int i = 1; i < N; i++) {
            int tempx = (C*x + D*y + E1) % F;
            int tempy = (D*x + C*y + E2) % F;
            a[i] = (tempx + tempy) % F;
            x = tempx;
            y = tempy;
        }
        s[1] = K;
        for (int i = 2; i <= N; i++) {
            //s[i] = (i*(power(K, i) - 1) % MOD)/(i - 1);
            s[i] = 0;
            for (int j = 1; j <= K; j++) {
                s[i] += power(j, i);
                s[i] %= MOD;
            }
            // s[i] %= MOD;
            // cout << s[i] << '\n';
        }
        cout << "Case #" << counter << ": ";
        solve(a, s, N, K);
        counter++;
    }
}   
