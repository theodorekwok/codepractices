#include <bits/stdc++.h>

using namespace std;

int count_spruce(vector<vector<char>> matrix) {
    int count = 0;
    
    vector<vector<int>> store(matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> row(matrix[i].size(), 0);
        store[i] = row;
    }

    for (int i = matrix.size() - 1; i >= 0; i--) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (i == matrix.size() - 1) {
                if (matrix[i][j] == '*') {
                    store[i][j] = 1;
                }
                else {
                    store[i][j] = 0;
                }   
            }
            else {
                if (matrix[i][j] == '*') {
                    if (j == 0 || j == matrix[i].size() - 1) {
                        store[i][j] = 1;
                    }
                    else {
                        int min = store[i + 1][j - 1];
                        for (int w = j - 1; w <= j + 1; w++) {
                            if (store[i + 1][w] < min) {
                                min = store[i + 1][w];
                            }
                        } 
                        store[i][j] = min + 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < store.size(); i++) {
        for (int j = 0; j < store[i].size(); j++) {
            count += store[i][j];
        }
    }
    return count;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<char>> matrix(n);
        for (int i = 0; i < n; i++) {
            vector<char> row(m);
            for (int j = 0; j < m; j++) {
                cin >> row[j];
            }
            matrix[i] = row;
        }

        int spruce = count_spruce(matrix);
        cout << spruce << '\n';
    }
    return 0;
}
