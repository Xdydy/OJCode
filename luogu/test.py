s = str(input())
cnt=1
ans=0
n = len(s)
for i in range(0,n-1):
    if s[i] >= '0' and s[i] <= '9':
        ans = ( ans + cnt*int(s[i]) ) % 11
        cnt += 1
ok=False
if s[-1] == 'X':
    if ans == 10:
        ok = True
else:
    if ans == int(s[-1]):
        ok = True
if ok:
    print("Right")
else:
    if ans == 10 :
        ans = "X"
    print("%s%s" % (s[0:-1],ans))