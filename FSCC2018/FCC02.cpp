/*
 *	Abhishek(abhiy13)
 *	Chandigarh University
*/
 
#include "bits/stdc++.h"
	using namespace std;
 
#define		io				std::ios::sync_with_stdio(false);
#define		FOR(i,n)		     for(int i = 0 ; i < n ; i++)
#define		rep(i,a,b)		for(int i = a ; i < b ; i++)
#define   	rrep(i,a,b)		for(int i = a ; i > b ; i--)
#define 	     timer			cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";	
 
typedef long long ll;
typedef unsigned long long llu;
 
int main(){
	io
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
         string s;
         cin >> s;
         int n = s.length();
         int hh, mm, ss;
         hh = (s[0] - '0') * 10 + (s[1] - '0');
         mm = (s[3] - '0') * 10 + (s[4] - '0');
         ss = (s[6] - '0') * 10 + (s[7] - '0');
     
         if (hh < 12 && s[8] == 'P') hh += 12;
         if (hh == 12 && s[8] == 'A') hh = 0;
     
         printf("%02d:%02d:%02d\n", hh, mm, ss);
 
    return 0;
	#ifdef ABHI
		timer
	#endif
	return 0;
} 
