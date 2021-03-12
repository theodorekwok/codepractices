#include <bits/stdc++.h>

using namespace std;


#define pq priority_queue

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    
    map<int,vector<int>> store;
    pq<int> q;
    vector<int> pos;
    int index = 1;
    int cur = 1;
    while (t--) {
        int type;
        cin >> type;
        int val;
        if (type == 1) {
            cin >> val;
            store[val].push_back(index);
            index++;
            q.push(val);
            pos.push_back(val);
        }
        else {
            if (type == 2) {
                while (store.find(pos[cur - 1]) == store.end()) {
                    cur++;
                }
                ans.push_back(cur);
                store[pos[cur - 1]].erase(store[pos[cur - 1]].begin() + 0);
                if (store[pos[cur - 1]].size() == 0) {
                    store.erase(pos[cur - 1]);
                    if (pos[cur - 1] == q.top()) {
                        q.pop();
                    }
                }
                cur++;
            }
            else {
                int max = q.top();
                while (store[max].size() == 0) {
                    q.pop();
                    max = q.top();
                }
                ans.push_back(store[max][0]);
                if (store[max][0] == cur) {
                    cur++;
                }
                store[max].erase(store[max].begin() + 0);
                if (store[max].size() == 0) {
                    store.erase(max);
                    q.pop();
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
