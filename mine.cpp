#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(string s, int a, int b) {
    ll index = 0;
    vector<vector<ll>> bands;
    while (index < s.size()) {
        ll start = index;
        while (s[index] == '1') {
            index++;
        }
        ll end = index;
        if (start != end) {
            bands.push_back({start, end});
        }
        index++;
    }
    ll cost = bands.size() * a;
    if (bands.size() == 1 || bands.size() == 0) {
        cout << cost << '\n';
        return;
    }
    vector<ll> gaps;
    for (int i = 1; i < bands.size(); i++) {
        gaps.push_back(bands[i][0] - bands[i - 1][1]);
        // cout << bands[i][0] - bands[i - 1][1] << '\n';
    }
    sort(gaps.begin(), gaps.begin() + gaps.size());
    for (int i = 0; i < gaps.size(); i++) {
        ll new_cost = cost - a + gaps[i]*b;
        cost = min(new_cost, cost);
    }
    cout << cost << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string m;
        cin >> m;
        solve(m, a, b);
    }
    return 0;
}
