#include <bits/stdc++.h>

using namespace std;

int get_min(vector<int> arr) {
    int sum = 0;
    bool equal = true;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (i != 0) {
            if (arr[i] != arr[i - 1]) {
                equal = false;
            }
        }
    }
    if (equal || arr.size() == 1) {
        return 0;
    }
    vector<int> factors;
    for (int i = 1; i < arr.size(); i++) {
        if (sum % i == 0) {
            factors.push_back(sum/i);
        }
    }
    int special_factor = 1;
    for (int i = factors.size() - 1; i >= 0; i--) {
        int factor = factors[i];
        int index = 0;
        int add = 0;
        bool possible = true;
        while (index < arr.size()) {
            if (add < factor) {
                add += arr[index];
                index++;
                if (add != factor && index == arr.size()) {
                    possible = false;
                }
            }
            else {
                if (add > factor) {
                    possible = false;
                    break;
                }
                else {
                    add = 0;
                }
            }
        }
        if (possible) {
            special_factor = factor;
            break;
        }
    }

    return arr.size() - (sum/special_factor);

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
        int min = get_min(arr);
        cout << min << '\n';
    }
    return 0;
}
