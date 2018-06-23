/****************************************************
*****************************************************
**               Abhishek(abhiy13)                 **          
**             Chandigarh University               **
**   https://www.youtube.com/watch?v=r6zIGXun57U   **
*****************************************************
****************************************************/ 
 
 
#include "bits/stdc++.h"
    using namespace std;
 
 
//`````````````````````````````````````````````````````Random Stuff Here```````````````````````````````````````````````````````//
    
#define io std::ios::sync_with_stdio(false);
#define FOR(i,n) for(ll i = 0 ; i < n ; i++)
#define FORR(i,a,b) for(ll i = a ; i < b ; i++)
#define RFOR(i,a,b) for(ll i = a ; i > b ; i--) 
#define all(x) begin(x),end(x)
#define SZ(x) x.size()
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define clr(x) memset(x,0,sizeof(x))
#define vclr(x,y) memset(x,y,sizeof(x))
#define rsort(x) sort(x.rbegin(),x.rend())
#define F first
#define S second
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif   
 
 
//``````````````````````````````````````````````````````Start of Program`````````````````````````````````````````````````//
 
 
//Its always Better to make your own structures rather than using STL Paies :)
 
struct abhi{
    ll val , pos;
}a[1000000];
 
 
// Basic Idea Of Segtree Implemetation :: use a range max SegTree and have its position as well
// When required it use it :)
 
ll build(ll idx , ll s , ll e , ll A[]){
    if(s==e){
        a[idx].val = A[s];
        a[idx].pos = s;
        return A[s];
    }else{
        ll mid = (s+e)/2;
        ll k = build(2*idx,s,mid,A);
        ll p = build(2*idx+1,mid+1,e,A);
        a[idx].val = max(k,p);
        if(a[idx].val == k){
            a[idx].pos = a[2*idx].pos; 
        }else{
            a[idx].pos = a[2*idx+1].pos; 
        }
        return a[idx].val;
    }
}
 
void uppd(ll idx , ll s , ll e , ll in , ll vall , ll A[]){
    
    if(s==e){
        A[in] = vall;
        a[idx].val = vall;
        a[idx].pos = in;
        return;
    }else{
        ll mid = (s+e)/2;
        // Only search the first half if the index lies in the first half , this also reduces time complexity
        if(s <= in && in <= mid){
          uppd(2*idx,s,mid,in,vall,A);
        }else{
          uppd(2*idx+1,mid+1,e,in,vall,A);
        }
        ll k = a[2*idx].val;
        ll p = a[2*idx+1].val;
        a[idx].val = max(k,p);
    
        //Always have your max element and its position at the parent node
 
        if(a[idx].val == k){
            a[idx].pos = a[2*idx].pos;
        }else{    
            a[idx].pos = a[2*idx+1].pos;
        }
    }
 
}
 
 
// Query is Perhaps the most easy 
 
abhi qq(ll idx , ll s , ll e , ll lf , ll rf){
    
    if(rf<s || e < lf){
        abhi asd;
        asd.val = -2;
        return asd;
    }
    if(lf <= s && e <= rf){
        return a[idx];
    }
    ll mid = (s+e)/2;
    abhi k = qq(2*idx,s,mid,lf,rf);
    abhi p = qq(2*idx+1,mid+1,e,lf,rf);
    if(max(k.val,p.val)==k.val) return k;
    else return p;
 
}
 
 
bool valid(ll a , ll b , ll c){
     return ((a+b>c) && (b+c>a) && (a+c>b));
}
 
 
// Just declred the arrays of size 1000000 (1e6) for compile time memory allocation 
 
int main(){
    io
    //freopen("input.txt" ,"r" , stdin);
    ll n , q;
    cin>>n>>q;
    ll ar[1000000];
    FOR(i,n) cin>>ar[i];
    abhi temp[1000000];
    build(1,0,n-1,ar); // building the tree
    ll l , r , qt;
    //FOR(i,25) cout<<a[i].val<<" ";
    //cout<<endl;
    while(q--){
        cin>>qt>>l>>r;
        if(qt==1){
            ar[l-1] = r;
            uppd(1,0,n-1,l-1,r,ar);
            //FOR(i,25) cout<<a[i].val<<" ";
            //cout<<endl;
        }else{
             
            ll c = 0;
            if(r-l+1<3){  
                // if query is of a segment less than size three               
                cout<<0<<endl;                
            }else{
                // else the fun part
                // basic idea used was to take the maximum element of the range and replace it by -1 so that the next highest 
                // element in the tree shows up and then restore all the values of the array thats why we use a temp array !!! 
 
                 ll max = qq(1,0,n-1,l-1,r-1).pos;
                 ll aa = ar[max];
                 uppd(1,0,n-1,max,-1,ar);
                 temp[c].pos = max;
                 temp[c].val = aa;
                 c++;
                 
                 ll mx = qq(1,0,n-1,l-1,r-1).pos;
                 ll ab = ar[mx];
                 uppd(1,0,n-1,mx,-1,ar);
                 temp[c].pos = mx;
                 temp[c].val = ab;
                 c++;
                 
                 ll mxx = qq(1,0,n-1,l-1,r-1).pos;
                 ll ac = ar[mxx];
                 
                 while(!valid(aa,ab,ac)){
                         aa = ab;
                         ab = ac;
                         uppd(1, 0, n-1, mxx, -1, ar);
                         temp[c].pos = mxx;
                         temp[c].val = ac;
                         c++;
                         if(c > r-l+1)
                             break;
                         mxx = qq(1, 0, n-1, l-1, r-1).pos;
                         ac = ar[mxx];
                 }
 
                 if(valid(aa,ab,ac)){
                     cout<<aa+ab+ac<<endl;
                 }else{
                     cout<<0<<endl;
                 }
                 for(ll i = c-1 ; i >= 0 ; i--){
                     uppd(1,0,n-1,temp[i].pos,temp[i].val,ar);
                 }
           }
        }
    }
    return 0;
}
 
// Thanks !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11 
 
