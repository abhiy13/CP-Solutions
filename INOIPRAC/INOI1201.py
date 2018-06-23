n = int(input())
arr = []
for i in range(n):
	a , b , c = list(map(int, input().split()))
	arr.append([a , b+c])
 
arr.sort(key = lambda x : -x[1])
 
for i in range(1,n):
	arr[i][0] += arr[i-1][0]
 
res = -1
 
for i in arr:
	res = max(res , i[0] + i[1])
 
print(res) 
