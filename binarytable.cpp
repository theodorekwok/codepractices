#include <bits/stdc++.h>

using namespace std;


void three(vector<string> &table, vector<vector<int>> &ans, int i, int j) {
    vector<int> seq;
    for (int r = i; r < i + 2; r++) {
        for (int c = j; c < j + 2; c++) {
            if (table[r][c] == '1') {
                table[r][c] = '0';
                seq.push_back(r);
                seq.push_back(c);
            }
        }
    }
    ans.push_back(seq);
}

void two(vector<string> &table, vector<vector<int>> &ans, int i, int j) {
    int num_zero = 0;
    vector<int> seq;
    for (int r = i; r < i + 2; r++) {
        for (int c = j; c < j + 2; c++) {
            //cout << "here2" << '\n';
            if (table[r][c] == '1' && num_zero == 0) {
                table[r][c] = '0';
                seq.push_back(r);
                seq.push_back(c);
                num_zero++;   
            }
            else if (table[r][c] == '0') {
                table[r][c] = '1';
                seq.push_back(r);
                seq.push_back(c);
            }
        }
    }
    ans.push_back(seq);
    three(table, ans, i, j);
} 


void solve(vector<string> &table, int n, int m) {
    vector<vector<int>> ans;
    vector<string> d = table;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 >= n || j + 1 >= m) {
                continue;
            }
            int nz = 0;
            vector<vector<int>> sz;
            vector<vector<int>> so;
            
            if (table[i][j] == '0') {
                nz++;
                sz.push_back({i, j});
            }
            else {
                so.push_back({i, j});
            }

            if (table[i+1][j] == '0') {
                nz++;
                sz.push_back({i+1, j});
            }
            else {
                so.push_back({i+1, j});
            }
            
            if (table[i][j+1] == '0') {
                nz++;
                sz.push_back({i, j+1});
            }
            else {
                so.push_back({i, j+1});
            }
            
            if (table[i+1][j+1] == '0') {
                nz++;
                sz.push_back({i+1, j+1});
            }
            else {
                so.push_back({i+1, j+1});
            }
            /*for (int i = 0; i < sz.size(); i++) {
                cout << sz[i][0] << ' ' << sz[i][1] << '\n';
            }*/
            if (nz == 0) {
                vector<int>seq;
                for (int index = 0; index < 3; index++) {
                    seq.push_back(so[index][0]);
                    seq.push_back(so[index][1]);
                    table[so[index][0]][so[index][1]] = '0';
                }
                ans.push_back(seq);
                vector<int>second_seq;
                table[so[3][0]][so[3][1]] = '0';
                second_seq.push_back(so[3][0]);
                second_seq.push_back(so[3][1]);
                table[so[0][0]][so[0][1]] = '1';
                table[so[1][0]][so[1][1]] = '1';
                second_seq.push_back(so[0][0]);
                second_seq.push_back(so[0][1]);
                second_seq.push_back(so[1][0]);
                second_seq.push_back(so[1][1]);
                ans.push_back(second_seq);
                two(table, ans, i, j);
            }
            else if (nz == 1) {
                vector<int>seq;
                for (int index = 0; index < so.size(); index++) {
                    seq.push_back(so[index][0]);
                    seq.push_back(so[index][1]);
                    table[so[index][0]][so[index][1]] = '0';
                }    
                ans.push_back(seq);
            }
            else if (nz == 2) {
                two(table, ans, i, j);
            }
            else if (nz == 3) {
                vector<int>seq;
                table[so[0][0]][so[0][1]] = '0';
                table[sz[0][0]][sz[0][1]] = '1';
                table[sz[1][0]][sz[1][1]] = '1';
                seq.push_back(so[0][0]);
                seq.push_back(so[0][1]);
                seq.push_back(sz[0][0]);
                seq.push_back(sz[0][1]);
                seq.push_back(sz[1][0]);
                seq.push_back(sz[1][1]);
                ans.push_back(seq);
                two(table, ans, i, j);
            }
            /*for (int ind = 0; ind < n; ind++) {
                cout << table[ind] << '\n';
            }
            cout << '\n';*/
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout << table[i] << '\n';
    }*/


    /*for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 6; j += 2) {
            if (d[ans[i][j]][ans[i][j+1]] == '1') {
                d[ans[i][j]][ans[i][j+1]] = '0';
            }
            else {
                d[ans[i][j]][ans[i][j+1]] = '1';
            }

            for (int ind = 0; ind < d.size(); ind++) {
                cout << d[ind] << '\n';
            }
            cout << '\n';
        }
    }*/


    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> table(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            table[i] = s;
        }
        solve(table, n, m);
    }
}
