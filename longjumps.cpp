#include <bits/stdc++.h>


using namespace std;


long get_max(vector<long> arr) {
    vector<unsigned long long> store_arr(arr.size(), 0);
    vector<unsigned long long> prev_add(arr.size(), 0);
    for (int i = 1; i < arr.size(); i++) {
        store_arr[i] = arr[i]; 
    }
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] + i  < arr.size()) {
            if (store_arr[arr[i] + i] - prev_add[arr[i] + i] + store_arr[i] > store_arr[arr[i] + i]) {
                store_arr[arr[i] + i] -= prev_add[arr[i] + i];
                store_arr[arr[i] + i] += store_arr[i];
                prev_add[arr[i] + i] = store_arr[i];
            }
        }
    }

    unsigned long long max = store_arr[1];
    for (int i = 0; i < store_arr.size(); i++) {
        if (store_arr[i] > max) {
            max = store_arr[i];
        }
    } 
    return max;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        

        long max = get_max(arr);
        cout << max << '\n';
    }

}
