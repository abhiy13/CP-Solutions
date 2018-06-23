#include "bits/stdc++.h"
	using namespace std;
 
int main() {
           int c,f;
           cin >> c >> f;
           int graph[c][c];
           for(int i = 0;i < c;i++)
                   for(int j = 0;j < c;j++)
                           graph[i][j] = 100000007;
           for(int i = 0;i < c;i++)
                   graph[i][i] = 0;
           int x,y,p;
           for(int i = 0;i < f;i++) {
                   cin >> x >> y >> p;
                   graph[x-1][y-1] = p;
                   graph[y-1][x-1] = p;
           }
           int dist[c][c], i, j, k;
           for(i = 0; i < c; i++)
               for (j = 0; j < c; j++)
                   dist[i][j] = graph[i][j];
           for(k = 0; k < c; k++) {
                 for(i = 0; i < c; i++) {
                       for(j = 0; j < c; j++) {
                             if(dist[i][k] + dist[k][j] < dist[i][j])
                                           dist[i][j] = dist[i][k] + dist[k][j];
                         }
                  }
           }
           int ans = 0;
           for(int i = 0;i < c;i++)
                   for(int j = 0;j < c;j++)
                           ans = max(ans,dist[i][j]);
           cout << ans << endl;
           return 0;
} 
