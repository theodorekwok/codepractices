#include <bits/stdc++.h>

using namespace std;


int remove(vector<int> arr) {
    map<int,vector<int>> store;
    for (int i = 0; i < arr.size(); i++) {
        store[arr[i]].push_back(i);
    }
    if (store.size() == 1) {
        return 0;
    }
    int min_interval = INT_MAX;
    for (auto itr = store.begin(); itr != store.end(); itr++) {
        int num_interval = 0;
        if (itr->second.size() == 1) {
            if (itr->second[0] == 0 || itr->second[itr->second.size() - 1] == arr.size() - 1) {
                num_interval = 1;
            }
            else {
                num_interval = 2;
            }
        }
        else {
            for (int i = 0; i < itr->second.size(); i++) {
                // cout << itr->second[i] << ' ' << itr->second[i - 1] << '\n';
                if (i == 0) {
                    if (itr->second[i] != 0) {
                        num_interval++;
                    }
                }
                else {
                    if (itr->second[i] - itr->second[i - 1] > 1) {
                        num_interval++;
                    }
                    if (i == itr->second.size() - 1 && itr->second[i] != arr.size() - 1) {
                        num_interval++;
                    }
                }
            }
        }
        // cout << num_interval << ' ' << itr->first << '\n';
        if (num_interval < min_interval) {
            min_interval = num_interval;
            if (min_interval == 1) {
                return 1;
            }
        }
    }
    return min_interval;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int minimum = remove(arr);
        cout << minimum << '\n';
    }
    return 0;
}
