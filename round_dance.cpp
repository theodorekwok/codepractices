#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;    
    }
    ans /= (n * n/2);
    cout << ans << '\n';
    return 0;
}
