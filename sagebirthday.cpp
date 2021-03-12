#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[100000];

void solve(ll arr[], int n) {
    int max = (n % 2 == 0) ? n / 2 - 1: n / 2;
    sort(arr, arr + n);
    for (int i = 1; i < n; i += 2) {    
        ll temp = arr[i];
        arr[i] =  arr[i - 1];
        arr[i - 1] = temp;
    }
    cout << max << '\n';
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(arr, n);
}

