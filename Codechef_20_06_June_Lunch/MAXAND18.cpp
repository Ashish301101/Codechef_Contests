//This is my solution for 'Maximum AND' from the June Lunchtime
//Question Link: https://www.codechef.com/LTIME85B/problems/MAXAND18

#include <bits/stdc++.h>

using namespace std;
long ar[100000];
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;



        for(int i=0;i<n;i++)
        {
            fflush(stdin);
            fflush(stdout);
            cin>>ar[i];
        }

        int bin[n][31];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<31;j++)
            {
                bin[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            long c = ar[i];
            for(int j=0;j<31;j++)
            {
                bin[i][j] = c%2;
                c/=2;
            }
        }
        long long br[31];
        int br2[31];
        for(int i=0;i<31;i++)
        {
            br[i] = 0;
            br2[i]=0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(bin[i][j] == 1)
                {
                    br[j]+=pow(2,j);
                }
            }
        }

        for(int i = 0;i<k;i++)
        {
            int maxind = 0;
            for(int j=0;j<31;j++)
            {
                if(br[maxind]<br[j])
                {
                    maxind = j;
                }
            }
            br2[maxind] = 1;
            br[maxind] = -1;
        }
        long ans=0;
        for(int i=0;i<31;i++)
        {
            if(br2[i] == 1)
            {
                ans+=pow(2,i);
            }
        }

        cout<<ans<<endl;
    }
}