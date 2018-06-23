#include <bits/stdc++.h>
using namespace std;
int main() {
	int N,K,i;
	long long int A,tmp1;
	scanf("%lld %d %d",&A,&N,&K);
	while(K--)
	{
		if(A<=0)
		printf("0 ");
		else
		printf("%lld ",A%(N+1));
		A=A/(N+1);
	}
	printf("\n");
	return 0;
}
 
