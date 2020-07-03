//This is my solution for 'Equality' from the January Long Challenge
//Question Link: https://www.codechef.com/JAN20B/problems/ISBIAS

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    int ar[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    int increasing=ar[1]>ar[0]?1:0;
    int ctr=0;
    int L[n]={0};
    int R[n]={0};
    if(ar[n-2]>ar[n-1])
    {
        ar[n] = ar[n-1]-1;
    }
    else
        ar[n] = ar[n-1]+1;

    int x=0;
    for(int i=0;i<n;i++)
    {
        R[i]=x;
        L[i]=x;
        if(ar[i]<ar[i+1])
        {
            if(increasing != 1)
            {
                increasing=1;
                L[i]=x;
                x++;
                R[i]=x;
            }
        }
        else
        {
            if(increasing!=0)
            {
                increasing=0;
                L[i]=x;
                x++;
                R[i]=x;
            }
        }

        //
    }
    L[0]=0;
    R[0]=0;
/*
    for(int i=0;i<n;i++)
    {
        cout<<i<<") "<<ar[i]<<"--"<<L[i]<<"--"<<R[i]<<endl;
    }
*/
    //cout<<endl;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(r == l+1)
        {
            cout<<"NO"<<endl;
            continue;
        }

        ctr = L[r]-R[l];
        //ctr--;

        if(ctr%2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

}
