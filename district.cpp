#include <bits/stdc++.h>

#define ll long long

using namespace std;

void dfs(vector<vector<int>> al, vector<bool> &visited, int district) {
    queue<int> s;
    s.push(district);
    visited[district] = true;
    vector<int> ans;
    while (!s.empty()) {
        int d = s.front();
        s.pop();
        //ans.push_back(d);
        //cout << "representative: " << d << ' ';

        for (int i = 0; i < al[d].size(); i++) {
            if (!visited[al[d][i]]) {
                visited[al[d][i]] = true;
                s.push(al[d][i]);
                cout << d << ' ' << al[d][i] << '\n';
            } 
        } 
    }
    /*for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }*/
    /*
    for (int i = 0; i < al[district].size(); i++) {
        if (!visited[al[district][i]]) {
            cout << district << ' ' << al[district][i] << '\n';
            dfs(al, visited, al[district][i]);
        }
    }*/
}

void solve(vector<ll> a) {
    // vector<vector<int>> connections;
    vector<vector<int>> al(a.size());
    bool got_connections = false;
    for (int i = 1; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] != a[j]) {
                got_connections = true;
                // connections.push_back({i, j});
                al[i].push_back(j); 
                al[j].push_back(i);
            }
        }
    }
    /*for (int i = 1; i < al.size(); i++) {
        for (int j = 0; j < al[i].size(); j++) {
            cout << al[i][j] << ' ';
        }
        cout << '\n';
    }*/

    if (!got_connections) {
        cout << "NO" << '\n';
        return;
    }
    
    vector<bool> visited(a.size(), false);
    cout << "YES" << '\n';
    dfs(al, visited, 1);

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
}
