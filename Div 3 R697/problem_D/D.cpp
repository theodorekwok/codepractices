#include <bits/stdc++.h>

#define ll long long

ll c_one[1000000] = {0};
ll c_two[1000000] = {0};


using namespace std;

int bs(ll c[], int start, int end, ll diff) {
    
    int size = end - start;
    end--;
    while (start <= end) {
        int middle = (start + end)/2;
        if (c[middle] == diff) {
            return middle;
        }
        else if (c[middle] > diff) {
            end = middle - 1;
        }
        else if (c[middle] < diff) {
            start = middle + 1;
        }
    }
    // cout << start << ' ' << size << '\n';
    // cout << c[start] << ' ' << diff << '\n';
    if (start == size) {
        return -1;
    }

    return start;
}


void score(int *ans, ll m, int size_first, int size_second, int factor_one, int factor_two, ll c_first[], ll c_second[]) {
    bool possible = false;
    for (int i = 0; i < size_first; i++) {
        if (c_first[i] >= m) {
            *ans = min(*ans, (i + 1)*factor_one);
            return;
        }
        else {
            ll diff = m - c_first[i];
            int index = bs(c_second, 0, size_second, diff);
            // cout << "index" << ' ' << index << ' ' << "diff " << diff << '\n';
            if (index != -1) {
                possible = true;
                int curr_score = (i + 1)*factor_one + (index + 1)*factor_two;
                *ans = min(*ans, curr_score);
            }
        }    
    }
    if (!possible && size_first != 0) {
        *ans = -1;
    }
}

void solve(ll m, vector<vector<ll>> cm) {
    sort(cm.begin(), cm.end(), [](const vector<ll> &a, const vector<ll> &b) {
        return a[0] > b[0];
    });
    int size_one = 0;
    int size_two = 0;
    for (int i = 0; i < cm.size(); i++) {
        if (cm[i][1] == 1) {
            if (size_one == 0) 
                c_one[size_one] = cm[i][0];
            else 
                c_one[size_one] = cm[i][0] + c_one[size_one - 1];
            size_one++;
        }
        else {
            if (size_two == 0)
                c_two[size_two] = cm[i][0];
            else
                c_two[size_two] = cm[i][0] + c_two[size_two - 1];
            size_two++;
        }
    }
    int ans = INT_MAX;
    int *ptr_ans = &ans;
    score(ptr_ans, m, size_one, size_two, 1, 2, c_one, c_two);
    score(ptr_ans, m, size_two, size_one, 2, 1, c_two, c_one);

    cout << ans << '\n';


}

int main() {
    int t;

    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<vector<ll>> cm(n);
        for (int i = 0; i < n; i++) {
            ll mem;
            cin >> mem;
            cm[i].push_back(mem); 
        } 
        for (int i = 0; i < n; i++) {
            ll cost;
            cin >> cost;
            cm[i].push_back(cost);
        }
        solve(m, cm);
    }
    return 0;
}
