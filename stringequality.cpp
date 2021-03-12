#include <bits/stdc++.h>

using namespace std;


bool check_equality(string a, string b, int k) {
    int arr_a[26] = {0};
    int arr_b[26] = {0};
    for (int i = 0; i < a.size(); i++) {
        arr_a[a[i] - 'a']++;
        arr_b[b[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (arr_a[i] < arr_b[i]) {
            return false;
        }

        int difference = arr_a[i] - arr_b[i];
        if (difference % k != 0) {
            return false;
        }

        arr_a[i] -= difference;
        if (difference == 0) {
            arr_a[i] = 0;
        }
        if (i == 25 && arr_a[i] != 0) {
            return false;
        }
        if (i <= 24) {
            arr_a[i + 1] += difference;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        bool possible = check_equality(a, b, k);
        if (possible) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }
}
