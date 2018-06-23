#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
ll ar[2001][2001] , n  , m;
bool visited[2001][2001];
 
ll dx[] = {1 , 0 , -1 , 0};
ll dy[] = {0 , 1 , 0 , -1};
 
 
unordered_map <ll , unordered_map < ll , vector < pair <ll , ll> > > >  hass; 
 
ll solve(ll c1 , ll c2){
	memset(visited , false , sizeof visited);
	queue < pair <ll , ll> > Q;
	ll sz = (ll) hass[c1][c2].size() , curr = 0;
	Q.push(hass[c1][c2][0]);
	visited[hass[c1][c2][0].first][hass[c1][c2][0].second] = true;
	ll res = 0 , ans = 0;
	while(!Q.empty()){
		ll x = Q.front().first;
		ll y = Q.front().second;
	  Q.pop();
		for(int i = 0 ; i < 4 ; i++){
			if(x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m) continue;
			if(visited[x + dx[i]][y + dy[i]]) continue;
			if(ar[x + dx[i]][y + dy[i]] == c1 || ar[x + dx[i]][y + dy[i]] == c2){
				Q.push({x + dx[i] , y + dy[i]});
				visited[x + dx[i]][y + dy[i]] = true;
				res++;
			}
		}
		if(Q.empty() && curr != sz - 1){
		  Q.push(hass[c1][c2][++curr]);
		  visited[hass[c1][c2][curr].first][hass[c1][c2][curr].second] = true;
		  ans = max(ans , 1 + res);
		  res = 0 ; 
		}
	}
	return ans;
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef ABHI
	freopen("input3.txt" , "r" , stdin);
#endif
	cin>>n>>m;
	unordered_map <ll , ll> mp; 	
	vector <ll> cols;
	ll col_max = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>ar[i][j];
			if(mp[ar[i][j]] == 0){
				cols.push_back(ar[i][j]);
				mp[ar[i][j]]++;
			}else{
				mp[ar[i][j]]++;
			}
        }
    }
    unordered_map < ll , unordered_map < ll , bool > > done;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){ 
            for(int k = 0 ; k < 4; k++){
                ll x = i + dx[k] , y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m){
                    hass[ar[i][j]][ar[x][y]].push_back({x,y});
                    hass[ar[x][y]][ar[i][j]].push_back({i,j});
                    done[ar[i][j]][ar[x][y]] = done[ar[x][y]][ar[i][j]] = false;
                }
            }
        }
    }
	ll k = (ll)cols.size() , res = 2 , ii , jj;
	if(k == n*m){
		cout<<2<<endl;
		return 0;
	}
	if(k == 1 || k == 2){
		cout<<n*m<<endl;
		return 0;
	}
  sort(cols.begin() , cols.end() , [&](ll &a , ll &b){
    return mp[a] > mp[b];        
  });
	col_max = mp[cols[0]];
    for(int i = 0 ; i < k ; i++){
		if(cols[i] + col_max <= res) continue;
		for(int j = i ; j < k ; j++){
            if(done[cols[i]][cols[j]] || done[cols[j]][cols[i]]) continue;
            done[cols[i]][cols[j]] = done[cols[j]][cols[i]] = true;
			      if(mp[cols[i]] + mp[cols[j]] <= res) continue;
#ifdef ABHI
            ll pres = res;
#endif
            res = max(res , solve(cols[i] , cols[j]));
#ifdef ABHI
            if(pres < res){
                ii = i , jj = j;
            }
#endif
        }
	}
#ifdef ABHI
    cout << ii << ' ' << jj << endl;
#endif
    cout<<res<<endl;
#ifdef ABHI
	cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
	return 0;
} 
