#include <bits/stdc++.h>

using namespace std;

int r[500][500];
int c[500][500];

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<int,int> s;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> r[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
                if (i == 0) {
                    s[c[i][j]] = j;
                }
            }
        }
        map<int,int> order;
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s.find(r[i][j]) != s.end()) {
                    index = j;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            order[s[r[i][index]]] = i;
        }
        for (int i = 0; i < n; i++) {
            int index_row = order[i];
            for (int j = 0; j < m; j++) {
                cout << r[index_row][j] << ' ';
            }
            cout << '\n';
        }
    }
}
