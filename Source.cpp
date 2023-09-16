#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,-1,1 };
int ans = 0;
int a[25][25];
void check(int m, int u, int n) {
    a[m][u] = 1;
    ++ans;
    for (int i = 0; i < 4; i++) {
        int idx = m + dx[i];
        int idy = u + dy[i];
        if (idx >= 0 && idx < n && idy >= 0 && idy < n && a[idx][idy] == 0) {
            check(idx, idy, n);
        }
    }
}
int main() {
    int n, t, g; cin >> n >> t >> g;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    t--; g--;
    check(t, g, n);
    cout << ans;

    return 0;
}
