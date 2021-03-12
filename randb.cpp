#include <bits/stdc++.h>


using namespace std;


int get_max(vector<int> r, vector<int> b) {
    r.insert(r.begin(), 0);
    b.insert(b.begin(), 0);

    vector<vector<int>> matrix(b.size());
    for (int i = 0; i < b.size(); i++) {
        vector<int> row(r.size(), 0); 
        matrix[i] = row;
    }

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < r.size(); j++) {
            if (i == 0) {
                if (j == 0) {
                    matrix[i][j] = b[i] + r[j];
                }
                else {
                    matrix[i][j] = matrix[i][j - 1] + r[j];
                }
            }
            else {
                matrix[i][j] = matrix[i - 1][j] + b[i];
            }
        }
    }
    int max = 0;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < r.size(); j++) {
            // cout << matrix[i][j] << ' ';
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
    
        }
        // cout << '\n';
    }


    return max;


}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int max = get_max(r, b);
        cout << max << '\n';

    }
    return 0;
}
