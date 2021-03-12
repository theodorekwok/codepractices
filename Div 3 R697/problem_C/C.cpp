#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

void solve(int a, int b, vector<vector<int>> pair) {
    map<int, ll> s_b;
    map<int, ll> s_g;
    for (int i = 0; i < pair.size(); i++) {
        s_b[pair[i][0]]++;
        s_g[pair[i][1]]++;
    }
    ll num_ways = 0;
    /*ll ans = pair.size()*(pair.size() - 1)/2;
    for (auto itr = s_b.begin(); itr != s_b.end(); itr++) {
        ll n = itr->second;
        num_ways += (n-1)*n/2;
    }
    for (auto itr = s_g.begin(); itr != s_g.end(); itr++) {
        ll n = itr->second;
        num_ways += (n-1)*n/2;
    }
    ans -= num_ways;
    cout << ans << '\n';*/
    int k = pair.size();
    for (int i = 0; i < pair.size(); i++) {
        num_ways += (k - 1 - (s_b[pair[i][0]] - 1) - (s_g[pair[i][1]] - 1)); 
    }

    cout << num_ways/2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<vector<int>> pair(k);
        for (int i = 0; i < k; i++) {
            int id;
            cin >> id;
            pair[i].push_back(id);
        }
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            pair[j].push_back(id);
        }
        solve(a, b, pair);
    }

}
