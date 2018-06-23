for T in range(int(input())):
  a , b , n = map(int , input().split())
  if n%2 == 0:
    if a < 0:
      a = -a
    if b < 0:
      b = -b
  if n == 0 or a == b:
    print(0)
  elif a > b:
    print(1)
  else:
    print(2)  
