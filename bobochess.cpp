#include <bits/stdc++.h>

#define print(sx, sy) (cout << sx << ' ' << sy << '\n')

using namespace std;
 
bool a[101][101] = {{false}};

bool rc(int sx, int m) {
    for (int j = 1; j <= m; j++) {
        if (!a[sx][j]) {
            return false;
        }
    }
    return true;
}

void solve(int n, int m, int sx, int sy) {
    a[sx][sy] = true;
    int steps = 2;
    print(sx, sy);
    sx = 1;
    a[sx][sy] = true;
    print(sx, sy);
    while (steps < n*m) {
        while (!rc(sx, m)) {
            if (!a[sx][sy]) {
                print(sx, sy);
                a[sx][sy] = true;
                steps++;
            }
            while (sy + 1 <= m) {
                sy++;
                if (!a[sx][sy]) {
                    print(sx, sy);
                    a[sx][sy] = true;
                    steps++; 
                }
            }
            if (rc(sx, m)) break;    
            while (sy - 1 >= 1) {
                sy--;
                if (!a[sx][sy]) {
                    print(sx, sy);
                    a[sx][sy] = true;
                    steps++;
                }
            }
        }
        sx++;
        
    }
}


int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    solve(n, m, sx, sy);
}
