//This is my solution for 'Cache Hits' from the June Cookoff
//Question Link: https://www.codechef.com/COOK119B/problems/CACHEHIT

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
        int n,b,m;
        cin>>n>>b>>m;

        int ar[m];
        for(int i=0;i<m;i++)
        {
            cin>>ar[i];
        }

        int l = 9999,r=-1;

        int ans=0;
        for(int i=0;i<m;i++)
        {
            //cout<<"range: "<<l<<" to "<<r<<", elem: "<<ar[i]<<endl;
            if(ar[i] >=l && ar[i]<=r)
            {
                continue;
            }

            ans++;
            int cur = ar[i];

            if(cur%b==0)
            {
                l = cur;
                r = l+b-1;
            }
            else
            {
                l = cur/b;
                l = l*b;
                r = l+b-1;
            }


        }
         cout<<ans<<endl;

    }
}