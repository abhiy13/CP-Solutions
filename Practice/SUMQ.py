import bisect
 
t = int(input())
MOD = 1000000007
for _ in range(t):
    p, q, r = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    a.sort()
    c.sort()
    sum_a = []
    sum_c = []
    sum_a.append(a[0])
    sum_c.append(c[0])
    for i in range(1, p):
        sum_a.append((sum_a[i-1] + a[i]) % MOD)
    for i in range(1, r):
        sum_c.append((sum_c[i-1] + c[i]) % MOD)
    total = 0
    for i in range(q):
        inda = bisect.bisect_right(a, b[i])
        indc = bisect.bisect_right(c, b[i])
        # print(inda, indc, b[i])
        suma = 0
        sumc = 0
        if inda > 0 and indc > 0:
            suma = (sum_a[inda-1] + inda * b[i]) % MOD
            sumc = (sum_c[indc-1] + indc * b[i]) % MOD
        total += suma * sumc
        total %= MOD
    print(total) 
