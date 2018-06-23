//Tester Code Chef XP
#include <bits/stdc++.h>
 
using namespace std;
 
int a[105][105];
 
int main () {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        bool bad = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                int b = max(a[i - 1][j], a[i][j - 1]);
                b = max(1, b);
                if (a[i][j] == -1) {
                    a[i][j] = b;
                } else if (a[i][j] < b) {
                    bad = true;
                }
            }
        }
        if (bad) {
            cout << -1 << '\n';
        } else {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }
    }
 
    return 0;
} 
