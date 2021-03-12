#include <bits/stdc++.h>

using namespace std;


void getwinner(vector<long> &arr) {
    sort(arr.begin(), arr.end());
    unsigned long long a = 0;
    unsigned long long b = 0;
    bool alice_turn = true;
    for (long i = arr.size() - 1; i >= 0; i--) {
        if (alice_turn) {
            if (arr[i] % 2 == 0) {
                a += arr[i];
            }
            alice_turn = false;
        }
        else {
            if (arr[i] % 2 != 0) {
                b += arr[i];
            }
            alice_turn = true;
        }
    }

    if (a == b) {
        cout << "Tie" << '\n';
        return;
    }
    else if (a > b) {
        cout << "Alice" << '\n';
        return;
    }
    cout << "Bob" << '\n';
    return;

}

int main() {
    long t;
    cin >> t;
    for (long j = 0; j < t; j++) {
        long n;
        cin >> n;
        vector<long> arr(n);
        for (long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        getwinner(arr);

    }
    return 0;
    
}
