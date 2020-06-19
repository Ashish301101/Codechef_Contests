//This is my solution for 'Operations on a Tuple' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/TTUPLE

#include <bits/stdc++.h>

using namespace std;

long long gcd_basic(long long a, long long b)
{
    if(a==0)
        return b;
    return(gcd_basic(b%a,a));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        long long a,b,c,p,q,r;
        cin>>a>>b>>c>>p>>q>>r;

        //case 1 already solved
        if(a == p && b == q && c == r)
        {
            cout<<0<<endl;
            continue;
        }

        //two solved
        if((a == p && b == q) || (b ==q && c == r) || (a==p && c==r))
        {
            cout<<1<<endl;
            continue;
        }

        //one solved
        if(a==p)
        {
            if(b-q == c-r)
            {
                cout<<1<<endl;
                continue;
            }
            else
            {
                float x = (float)q/b;
                float y = (float)r/c;

                if(x == y && (int)x == x)
                {
                    cout<<1<<endl;
                    continue;
                }
                else
                {
                    cout<<2<<endl;
                    continue;
                }
            }
        }
        else if(c == r)
        {
            if(b-q == a-p)
            {
                cout<<1<<endl;
                continue;
            }
            else
            {
                float x = (float)q/b;
                float y = (float)p/a;

                if(x == y && (int)x == x)
                {
                    cout<<1<<endl;
                    continue;
                }
                else
                {
                    cout<<2<<endl;
                    continue;
                }
            }
        }
        else if(b == q)
        {
            if(a-p == c-r)
            {
                cout<<1<<endl;
                continue;
            }
            else
            {
                float x = (float)p/a;
                float y = (float)r/c;

                if(x == y && (int)x == x)
                {
                    cout<<1<<endl;
                    continue;
                }
                else
                {
                    cout<<2<<endl;
                    continue;
                }
            }
        }

        else
        {   //all diff equal
            if(a-p == b -q && a-p == c-r)
            {
                cout<<1<<endl;
                continue;
            }
            //two diffs are equal
            if(a-p == b -q || a-p == c-r || b-q == c-r)
            {
                cout<<2<<endl;
                continue;
            }

            //all factor equal
            float x = (float)p/a;
            float y = (float)q/b;
            float z = (float)r/c;


            if(x == y && x == z && x == (int)x)
            {
                cout<<1<<endl;
                continue;
            }

            //two factors are equal
            if(x == y && x == (int)x)
            {
                cout<<2<<endl;
                continue;
            }
            else if(x == z && x == (int)x)
            {
                cout<<2<<endl;
                continue;
            }
            else if(y == z && y == (int)y)
            {
                cout<<2<<endl;
                continue;
            }

            //making factors equal to x
            if(x == (int)x && p!=0)
            {
                float d = (float)a*q/p -b;
                if(d == (int)d && x == (float)r/(c+d))
                {
                    cout<<2<<endl;
                    continue;
                }
            }

            //making factors equal to y
            if(y == (int)y && q!=0)
            {
                float d = (float)b*p/q - a;
                if(d == (int)d && y == (float)r/(c+d))
                {
                    cout<<2<<endl;
                    continue;
                }
            }

            //making factors equal to z
            if(z == (int)z && r!=0)
            {
                float d = (float)c*q/r -b;
                if(d == (int)d && z == (float)p/(a+d))
                {
                    cout<<2<<endl;
                    continue;
                }
            }

            //making diff of b and q equal to p-a
            float k;
            if(b!=0)
            {
                k = (float)(q+a-p)/b;

                if(k == (int)k && r - c*k == p - a)
                {
                    cout<<2<<endl;
                    continue;
                }
            }


            //diff or b and q equal to r-c
            if(b!=0)
            {
                k = (float)(q+c-r)/b;

                if(k == (int)k && p - a*k == r - c)
                {
                    cout<<2<<endl;
                    continue;
                }
            }


            //diff or p and a to q-b, multiplying a by k
            if(a!=0)
            {
                k = (float)(p+b-q)/a;

                if(k == (int)k && r - c*k == q - b)
                {
                    cout<<2<<endl;
                    continue;
                }
            }

            if(p-a == q-b+r-c || q-b == p-a+r-c || r-c == p-a+q-b)
            {
                cout<<2<<endl;
                continue;
            }

            if((x == y*z || y == x*z || z == y*x) && x == (int)x && y == (int)y && z == (int)z)
            {
                cout<<2<<endl;
                continue;
            }


            ///solve one with diff and fix rest
            //solve a and subs into b and/or c
            long dif = p-a;
            if(dif+b!=0 &&(float)r/c == (float)q/(dif+b) && (float)r/c == r/c)
            {
                cout<<2<<endl;
                continue;
            }
            if(dif+c!=0 &&(float)r/(c+dif) == (float)q/(b) && (float)r/(c+dif) == r/(c+dif))
            {
                cout<<2<<endl;
                continue;
            }
            if(dif+b!=0 && dif+c!=0 && (float)r/(c+dif) == (float)q/(dif+b) && (float)r/(c+dif) == r/(c+dif))
            {
                cout<<2<<endl;
                continue;
            }

            //solve b and subs into a and/or c
            dif = q-b;
            if(dif+a!=0 && (float)r/c == (float)p/(dif+a)  && (float)r/(c) == r/(c))
            {
                cout<<2<<endl;
                continue;
            }
            if(dif+c!=0 &&(float)r/(c+dif) == (float)p/(a)  && (float)r/(c+dif) == r/(c+dif))
            {
                cout<<2<<endl;
                continue;
            }
            if( dif+c!=0 && dif+a!=0 && (float)r/(c+dif) == (float)p/(dif+a)  && (float)r/(c+dif) == r/(c+dif))
            {
                cout<<2<<endl;
                continue;
            }

            //solve c and subs into b and/or c
            dif = r-c;
            if( dif+a!=0 && (float)q/b == (float)p/(dif+a) && (float)p/(a+dif) == p/(a+dif))
            {
                cout<<2<<endl;
                continue;
            }
            if(b+dif!=0 && (float)q/(b+dif) == (float)p/(a) && (float)p/(a) == p/(a))
            {
                cout<<2<<endl;
                continue;
            }
            if(b+dif!=0 && dif+a!=0 && (float)q/(b+dif) == (float)p/(dif+a) && (float)p/(a+dif) == p/(a+dif))
            {
                cout<<2<<endl;
                continue;
            }

            ///solving one with mul and rest with diff
            //solve a and subs into b and c
            if(a!=0 && (float)p/a == p/a)
            {
                long mul = p/a;
                if(q-b == r-mul*c)
                {
                    cout<<2<<endl;
                    continue;
                }
                if(q-b*mul == r-c)
                {
                    cout<<2<<endl;
                    continue;
                }
                if(q-b*mul == r-mul*c)
                {
                    cout<<2<<endl;
                    continue;
                }
            }

            //solve b and subs into a and c
            if(b!=0 && (float)q/b == q/b)
            {
                long mul = q/b;
                if(p-a == r-mul*c)
                {
                    cout<<2<<endl;
                    continue;
                }
                if(p-a*mul == r-c)
                {
                    cout<<2<<endl;
                    continue;
                }
                if(p-a*mul == r-mul*c)
                {
                    cout<<2<<endl;
                    continue;
                }

            }

            //solve c and subs into b and a
            if(c!=0 && (float)r/c == r/c)
            {
                long mul = r/c;
                if(q-b == p-mul*a)
                {
                    cout<<2<<endl;
                    continue;
                }
                if(q-b*mul == p-a)
                {
                    cout<<2<<endl;
                    continue;
                }
                if(q-b*mul == p-mul*a)
                {
                    cout<<2<<endl;
                    continue;
                }
            }

            if(r!=0)
            {
                long long gcd = gcd_basic(p,gcd_basic(q,r));

                if(gcd!=1)
                {
                    long long P=p/gcd, Q=q/gcd,R=r/gcd;
                    if(a-P == b-Q && a-P == c-R)
                    {
                        cout<<2<<endl;
                        continue;
                    }
                }
            }
            
            if(a!=0 && b!=0 && c!=0)
            {
                long long ra = p/a,rb=q/b,rc=r/c;
                if(ra == rb && rb == rc)
                {
                    if(p%a == q%b && q%b == r%c)
                    {
                        cout<<2<<endl;
                        continue;
                    }
                }
            }
            cout<<3<<endl;
        }
    }
}