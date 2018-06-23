def fact(n):
     if n is 1 or n is 0:
          return 1
     return n*fact(n-1)
     
t = int(input())
 
for i in range(t):
     k = int(input())
     print(fact(k))
 
