import decimal

a,b,m,n = map(int,input().split())

arr_a = [0 for i in range(a*b)]
arr_b = [0 for i in range(a*b)]

for i in range(a*b):
    if i%b == 0:arr_a[i] = 1
    if i%a == 0:arr_b[i] = 1

count = 0
time = -1
for i in range((m-1)*b+1, m*b):
    if arr_b[i] == 1:
        count+=1
        if count == 1:
            time = i - ((m-1)*b)
         
decimal.getcontext().prec = n
f = decimal.Decimal(4)
d = decimal.Decimal(a*b)
if time!=-1: time = decimal.Decimal(time)

if time != -1:
    if len(str((f/d)*time))-2 == n:
        print(count, (f/d)*time)
    else :
        res = str((f/d)*time)
        res += "0"*(n-len(res)+2)
        print(count, res)
else:
    print(0,"-1." + "0"*n)

# 사실 개쉬움ㅋㅋ