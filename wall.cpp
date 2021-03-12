#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<string> store) {
    char top_one = store[0][1];
    char top_two = store[1][0];
    char bot_one = store[n - 2][n - 1];
    char bot_two = store[n - 1][n - 2];
    
    // left number is vertical, right number is horizontal
    if (top_one == top_two && bot_one == bot_two && top_one != bot_one) {
        cout << 0 << '\n';
        return;
    }
    else if (top_one == top_two && bot_one == bot_two && top_one == bot_one) {
        cout << 2 << '\n';
        cout << n - 1 << ' ' << n << '\n';
        cout << n << ' ' << n - 1 << '\n'; 
        return;
    }
    else if (top_one != top_two && bot_one == bot_two) {
        cout << 1 << '\n';
        if (top_two != bot_one) {
            cout << 1 << ' ' << 2 << '\n';
            return;
        }
        else {
            cout << 2 << ' ' << 1 << '\n';
            return;
        }
    }
    else if (top_one == top_two && bot_one != bot_two) {
        cout << 1 << '\n';
        if (bot_one != top_one) {
            cout << n << ' ' << n - 1 << '\n';
            return;
        }
        else {
            cout << n - 1 << ' ' << n << '\n';
        }
    }
    else {
        cout << 2 << '\n';
        // invert top one
        cout << 1 << ' ' << 2 << '\n';
        if (top_two == bot_one) {
            cout << n - 1 << ' ' << n << '\n';
            return;
        }
        else {
            cout << n << ' ' << n - 1 << '\n';
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> store(n);
        for (int i = 0; i < n; i++) {
            cin >> store[i];
        }
        solve(n, store);
    }
}
