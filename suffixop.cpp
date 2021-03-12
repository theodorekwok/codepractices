#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll get_operations(vector<ll> arr) {
    vector<ll> store;
    store.push_back(0);
    ll cummulative = 0;
    for (int i = 1; i < arr.size(); i++) {
        store.push_back(arr[0] - (cummulative + arr[i]));
        cummulative += (arr[0] - (cummulative + arr[i]));
    }
    
    /*for (int i = 0; i < store.size(); i++) {
        cout << store[i] << ' ';
    }
    cout << '\n';*/

    bool only_one_change = true;
    for (int i = 0; i < store.size(); i++) {
        if (store[i] != 0 && i != store.size() - 1) {
            only_one_change = false;
        }
    }
    bool all_equal = true;
    for (int i = 0; i < store.size(); i++) {
        if (store[i] != 0) {
            all_equal = false;
        }
    }
    if (only_one_change || all_equal || store.size() == 2) {
        return 0;
    }

    ll steps = 0;
    for (int i = 0; i < store.size(); i++) {
        steps += abs(store[i]);     
    }
    ll min = steps;
    ll track = steps;
    for (int i = 1; i < store.size(); i++) {
        track -= abs(store[i]);
        if (i == 1) {
            // case one make the first value equal to second value
            if (track < min) {
                min = track;
            }

            // case two make the second value equal to first value
            ll final_change = store[i] + store[i + 1];
            ll diff = abs(final_change) - abs(store[i + 1]);
            track += diff;
            if (track < min) {
                min = track;
            }
        }
        else if (i == store.size() - 1) {
            if (track < min) {
                min = track;
            }
        }
        else {
            ll final_change = store[i] + store[i + 1];
            ll diff = abs(final_change) - abs(store[i + 1]);
            track += diff;
            if (track < min) {
                min = track;
            }
        }
        track = steps;
    }

    return min;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll min = get_operations(arr);
        cout << min << '\n';
    }
    return 0;
}
