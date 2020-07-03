//This is my solution for 'Chef and Demonitisation' from the June Lunchtime
//Question Link: https://www.codechef.com/LTIME85B/problems/CHFMOT18


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
        long s,n;
        cin>>s>>n;

        if(s==1)
        {
            cout<<1<<endl;
            continue;
        }
        else if(n>=s)
        {
            if(s%2==0)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
            continue;
        }
        else
        {
            long ans = s/n;
            s-=ans*n;
            if(s%2==0)
            {
                if(s>0)
                    ans+=1;
            }
            else
            {
                if(s>1)
                ans+=2;
                else
                {
                    ans+=1;
                }
            }
            cout<<ans<<endl;
            continue;
        }
    }
}