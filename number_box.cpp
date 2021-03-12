#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> matrix) {
    int ans = 0;
    int count = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] <= 0) {
                count++;
            }
            ans += abs(matrix[i][j]);
        }
    }
    if (count % 2 == 0) {
        cout << ans << '\n';
        return;
    }
    else {
        int min = abs(matrix[0][0]);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (abs(matrix[i][j]) < min) {
                    min = abs(matrix[i][j]);
                }
            }
        }
        ans -= abs(min);
        ans += -1*min;
        cout << ans << '\n';
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++) {
            vector<int> row(m);
            for (int j = 0; j < m; j++) {
                cin >> row[j];

            }
            matrix[i] = row;
        }
        solve(matrix);
    }
    return 0;
}
