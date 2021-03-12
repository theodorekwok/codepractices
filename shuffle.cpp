#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(vector<ll> seq, ll n, int x, int m) {
    ll ans = 0;
    ll front = x;
    ll back = x;
    int i = 0;
    while (i < seq.size() && (x < seq[i] || x > seq[i+1])) {
        i += 2;
    }
    
    for (int j = i; j < seq.size(); j += 2) {
        if (seq[j+1] >= front && seq[j] <= back) {
            front = min(seq[j], front);
            back = max(seq[j+1], back);
        }
    }
    ans = back - front + 1;
    cout << ans << '\n';
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int x, m;
        cin >> x >> m;
        
        vector<ll> seq;
        for (int i = 0; i < m; i++) {
            ll f;
            ll b;
            cin >> f >> b;
            seq.push_back(f);
            seq.push_back(b);
        }
        solve(seq, n, x, m); 

    }
}   
