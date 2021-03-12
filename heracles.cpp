#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll w[100001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        vector<vector<int>> adjlist(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        // calculate the degrees of each node
        vector<int> edges(n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            edges[i] = adjlist[i].size();
            ans += w[i];
        }
        
        // store the nodes in a heap with max at top
        priority_queue<pair<int,int>> pq;
        for (int i = 1; i <= n; i++) {
            pq.push(pair<int,int>(w[i], i));
        }
        
        cout << ans << ' ';
        while (!pq.empty()) {
            pair<int,int> nv = pq.top();
            int weight = nv.first;
            int node = nv.second;
            if (edges[node] > 1) {
                ans += weight;
                cout << ans << ' ';
                edges[node]--;
            }
            else {
                pq.pop();
            }
        }
        cout << '\n';
    }   
}
