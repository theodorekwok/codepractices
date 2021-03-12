#include <bits/stdc++.h>


using namespace std;

#define ll long long int

ll get_sum(vector<ll> arr, ll x) {
    ll sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    bool still_divisible = true;
    int multiplier = x;
    while (still_divisible) {
        for (int i = 0; i < arr.size(); i++) {
            ll q = arr[i];
            if (q % x == 0) {
                arr[i] = q/x;
                sum += arr[i] * multiplier;
            }
            else {
                still_divisible = false;
                break;
            }
        }
        multiplier *= x;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll sum = get_sum(arr, x);
        cout << sum << '\n';
    }
    return 0;

}
