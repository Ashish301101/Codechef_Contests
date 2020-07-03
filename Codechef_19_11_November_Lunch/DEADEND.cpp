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
          int n;
          cin>>n;
          long ar[n];
          for(int i=0;i<n;i++)
          {
              cin>>ar[i];
          }

        long ans=0;
        long maxi = ar[0],mini = ar[0];
        for(int i=0;i<n;i++)
        {
            if(ar[i]>maxi)
            {
                maxi = ar[i];
            }
            if(ar[i]<mini)
            {
                mini = ar[i];
            }
        }
        bool ex[maxi-mini+1];
        for(long i = 0;i<=maxi-mini;i++)
        {
            ex[i]=0;
        }

        for(long i=0;i<n;i++)
        {
            ex[ar[i] - mini] = 1;
        }


        for(long i = 0;i<=maxi-mini;i++)
        {
            if(ex[i]==1)
            {
                if(ex[i+1]==0 && ex[i-1]==0)
                {
                    ans++;
                    ex[i+1] = 1;
                }
            }
        }
       cout<<ans<<endl;

      }
 }
