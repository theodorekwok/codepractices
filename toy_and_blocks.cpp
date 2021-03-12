#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll get_min(vector<ll> arr) {
    ll sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    // sort(arr.begin(), arr.begin() + arr.size());
    ll smallest_ele = arr[0];
    ll largest_ele = arr[0];
    vector<ll> diff_arr;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest_ele) {
            smallest_ele = arr[i];
        }
        if (arr[i] > largest_ele) {
            largest_ele = arr[i];
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        diff_arr.push_back(largest_ele - arr[i]);
    }
    ll sum_diff = 0;
    for (int i = 0; i < diff_arr.size(); i++) {
        sum_diff += diff_arr[i];
    }

    ll temp_diff = sum_diff - (largest_ele - smallest_ele);
    if (smallest_ele > temp_diff) {
        int add = 1;
        if (sum % (arr.size() - 1) == 0) {
            add = 0;
        }
        ll factor = sum/(arr.size() - 1) + add;
        return factor*(arr.size() - 1) - sum;
    }

    return temp_diff - smallest_ele;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll min = get_min(arr);
        cout << min << '\n';
    }
    return 0;
}
