#include <bits/stdc++.h>


using namespace std;

#define ll long long int


ll get_min(vector<int> friends, vector<ll> cost) {
    sort(friends.begin(), friends.end());
    ll sum = 0;
    int present_index = 1;
    for (int i = friends.size() - 1; i >= 0; i--) {
        if (friends[i] < present_index) {
            sum += cost[friends[i]];
        }
        else {
            sum += cost[present_index];
            if (cost[friends[i]] > cost[present_index]) {
                present_index++;
            }
        }
        
    }
    return sum;
}


int main() {
    int  t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> friends(n + 1);
        vector<ll> cost(m + 1);
        for (int i = 1; i <= n; i++) {
            cin >> friends[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> cost[i];
        }

        ll min = get_min(friends, cost);
        cout << min << '\n';
    }
    return 0;

}
