    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main(){
    int tt;cin>>tt;while(tt--){
    	    ll n,i,j,count=0,k=0;;
    	    cin>>n;
    	    ll p[n], r[n];
    	    for(i=0; i<n; i++) cin>>p[i];
    	    for(i=0; i<n; i++) cin>>r[i];
    	    sort(p,p+n);
    	    sort(r,r+n);
    	    for(i=0; i<n; i++){
    	    	for(j=k; j<n; j++){ 
    	    		if(p[i] <= r[j]){
    	    			count++;
    	    			k = j+1;
    	    			break;
    	    		}
    	    	}
    	    }
    	    cout<<count<<endl;
    
    }
    return 0;
    }   
