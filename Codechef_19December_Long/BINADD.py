#This is my solution for 'Addition' from the december Long challenge
#Question Link: https://www.codechef.com/DEC19B/problems/BINADD/

t = int(input())
while t:
    t=t-1
    A = input()
    B = input()
    alen = len(A)
    blen = len(B)
    a=0
    b=0
    iter=1
    for x in A:
        if x == '1':
            a=a+(2**(alen-iter))
        iter = iter+1
    #print(a)
    iter=1
    for x in B:
        if x == '1':
            b=b+(2**(blen-iter))
        iter = iter+1
        U=0
        V=0
        counter=0
    while b>0:
        U = a^b
        V = a&b
        a = U
        b = 2*V
        counter+=1
    print(counter)
