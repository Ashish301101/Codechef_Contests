#This is my solution for 'Increasing Decreasing' from the June Lunchtime
#Question Link: https://www.codechef.com/LTIME85B/problems/INCRDEC

t = int(input())

def solve():
    n = int(input())
    ar =  list(map(int,input().split()))
    ar.sort()
    arset = set(ar)

    if(len(ar) == len(arset)):
        print("YES")
        for x in ar:
            print(x,end=' ')
        print()
    else:
        if( ar[n-1] == ar[n-2]):
            print("NO")
            return;
        for i in range(1,n-1):
            if(ar[i-1] ==ar[i+1]):
                print("NO")
                return;
        ar2 = []
        print("YES")
        for i in range(1,n):
            if (ar[i] == ar[i-1]):
                ar2.append(ar[i])
                ar[i] = 394900
        for i in range(0,len(ar2)):
            ar.append(ar2[len(ar2)-i-1])
        for i in range(0,len(ar)):
            if(ar[i]!=394900):
                print(ar[i],end=' ')
        print()

while t:
    t-=1
    solve()