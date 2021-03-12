#include <bits/stdc++.h>

using namespace std;

int a[300000];


void solve(int a[], int n) {
    map<int,vector<int>> s;
    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) == s.end()) {
            s[a[i]] = {0, i + 1};
        }
        else {
            s[a[i]].push_back(i + 1);
        }
    }
    /*for (auto itr = s.begin(); itr != s.end(); itr++) {
        cout << "key :" << itr->first << " array: ";
        for (int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i] << ' ';
        }
        cout << '\n';
    }*/

    map<int,int> gap;
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        int max_gap = 0;
        for (int i = 1; i < itr->second.size(); i++) {
            max_gap = max(max_gap, itr->second[i] - itr->second[i - 1]);
        }
        max_gap = max(max_gap, n + 1 - itr->second[itr->second.size() - 1]);
        // cout << max_gap << ' ';
        if (gap.find(max_gap) == gap.end()) {
            gap[max_gap] = itr->first;
        }
        // cout << gap[max_gap] << '\n';
    }
    int v = -1;
    for (int i = 1; i <= n; i++) {
        if (gap.find(i) == gap.end()) {
            cout << v << ' ';
        }
        else {
            if (v == -1) {
                v = gap[i];
            }
            else {
                if (gap[i] > v) {
                    gap[i] = v;
                }
            }
            cout << gap[i] << ' ';
            v = gap[i];
        }
    }

    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, n);
    }
}
