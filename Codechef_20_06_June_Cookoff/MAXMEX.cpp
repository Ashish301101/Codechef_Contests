//This is my solution for 'Max Mex' from the June Cookoff
//Question Link: https://www.codechef.com/COOK119B/problems/MAXMEX

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int ar[n];

        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }

        int ma = -1;
        int cnt=0;
        int l=0,r=0;
        int br[m-1];
        int noms = 0;
        for(int i=0;i<m-1;i++)
        {
            br[i] = 0;
        }
        int brfill = 0;
        for(int i=0;i<n;i++)
        {

            if(brfill<m-1)
            {
                if(ar[i] < m)
                {
                    if(br[ar[i]-1] == 0)
                    {
                        br[ar[i]-1] = 1;
                        brfill++;
                    }
                }
                else if(ar[i] == m)
                {
                    noms++;
                }
            }
            if(brfill == m-1)
            {
                if(ar[i]!=m)
                {
                    r=i;
                }
                cnt = r-l+1;
                if(ma<cnt-noms)
                {
                    ma = cnt-noms;
                }

                if(ar[i]==m)
                {
                    noms++;
                }
            }
        }

        cout<<ma<<endl;
    }
}