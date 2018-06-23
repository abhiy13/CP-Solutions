#include <stdio.h>
 
int main(){
	int t;
	scanf("%d" , &t);
	while(t--){
		double n , k;
		scanf("%lf %lf" , &n , &k);
		printf("%.20lf\n" , 2+1.00*(k-1)/k*2.00*(n-1));
	}
	return 0;
} 
