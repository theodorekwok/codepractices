#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1000000007;

ll ncr(int n, int r) {
    vector<ll> row;
    row.push_back(1);
    int np = n;
    for (int i = 1; i <= r; i++) {
        row.push_back((row[i - 1]*(np)/i)%MOD);
        np--;
    }
    return row[r];
}


int main() {
    int n, r;
    cin >> n >> r;
    cout << "There are " << ncr(n, r) << " ways" << '\n';
    return 0;
}


