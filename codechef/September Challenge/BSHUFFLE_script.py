D = dict()

def rec(ls, n, N):
    if n == 0:
        str1 = ''.join(str(e) for e in ls)

        if (str1 in D):
            D[str1] += 1

        else:
            D[str1] = 1

        return
    
    for i in range(1, N+1):
        ls[N-1] , ls[i-1] = ls[i-1] , ls[N-1]
        rec(ls, n-1, N) 

n = int(input())
ls = list(range(1, n+1))
count = 0

rec(ls,n,n)

for i in D:
    print('{} {}'.format(i, D[i]))

maximimum = list(max(D, key=D.get))
minimum =  list(min(D, key=D.get))

[print(x, end=' ') for x in maximimum]
print()
[print(x, end=' ') for x in minimum]
print()