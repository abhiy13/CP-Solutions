#include <stdio.h>
#include <stdlib.h>
 
int main() 
{
  int t;
  char p[100];
  int i = 0,j;
  int count[41];
 
  scanf("%d",&t);
  while(i<t) {
    scanf("%s",p);
    count[i] = 0;
    j = 0;
    while(p[j] != '\0') {
 
      switch(p[j]) {
        case 'A':
        case 'D':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
          count[i]++;
          break;
        case 'B':
          count[i] +=2;
          break;
        default:
          break;
 
      }
      j++;
    }
    i++;
  } 
 
  for (i=0;i<t;i++) {
    printf("%d\n",count[i]);
  }
  return 0;
}  
