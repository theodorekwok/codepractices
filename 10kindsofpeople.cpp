#include <bits/stdc++.h>

using namespace std;


void fill(vector<vector<int>> &m, vector<vector<bool>> &visited, int i, int j, int r, int c, int type, int color) {
    if (i <= 0 || j <= 0 || i > r || j > c) {
        return;
    }
    if (m[i][j] != type) {
        return;
    }
    if (m[i][j] == color) {
        return;
    }
    visited[i][j] = true;
    m[i][j] = color;
    fill(m, visited, i + 1, j, r, c, type, color);
    fill(m, visited, i - 1, j, r, c, type, color);
    fill(m, visited, i, j + 1, r, c, type, color);
    fill(m, visited, i, j - 1, r, c, type, color);
}

void solve(vector<vector<int>> &m, int r, int c) {

    // preprocessing by creating vector of maps to store all possible access
    vector<vector<bool>> visited(r + 1, vector<bool>(c + 1, false));
    int color = 2;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!visited[i][j]) {
                int newcolor = m[i][j] + color;
                fill(m, visited, i, j, r, c, m[i][j], newcolor);
                color += 2;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (m[r1][c1] == m[r2][c2]) {
            if (m[r1][c1] % 2 == 0) {
                cout << "binary" << '\n';
            }
            else {
                cout << "decimal" << '\n';
            }
        }
        else {
            cout << "neither" << '\n';
        }
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }
    vector<vector<int>> m(r + 1, vector<int>(c + 1, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i + 1][j + 1] = (s[i][j] == '1') ? 1 : 0;
        }
    }
    solve(m, r, c);
}
