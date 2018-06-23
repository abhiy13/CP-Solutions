#include <stdio.h>
#include <math.h>
typedef unsigned long long int llu;
#define d(k) printf("%llu",k);
int main(void){
    	llu t;
	scanf("%llu",&t);
	while(t--){
		llu a,b;
		scanf("%llu %llu",&a,&b);
		llu ar[a];
		for(llu i=0;i<a;i++) scanf("%llu",&ar[i]);
		for(llu i=0;i<b;i++){
		     llu p;
		     scanf("%llu",&p);
			//d(p);
		     llu k =0;               
		     k=(llu)(p/ar[0] + 32768.)-32768;
		     //d(k);
			for(llu j=1;j<a;j++){
			  //   if(k=0) k=1;
				k/=ar[j];
				//printf("%llu",k);	
				//cout<<k;
			}
			printf("%llu ",(llu)(k + 32768.)-32768);	
		}
		printf("\n");
	}
	return 0;
}
 
 
