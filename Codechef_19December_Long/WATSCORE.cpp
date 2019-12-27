//This is my solution for 'That is my score!' from the december Long challenge
//Question Link: https://www.codechef.com/DEC19B/problems/WATSCORE/

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
            int a[n];
            int b[n];
            int totalscore=0;
            int sc[11];
            for(int i=0;i<11;i++)
            {
                sc[i]=0;
            }
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                cin>>b[i];
                if(sc[a[i]-1]<b[i])
                {
                    sc[a[i]-1] = b[i];
                }
            }
            for(int i=0;i<8;i++)
            {
                totalscore+=sc[i];
            }
            cout<<totalscore<<endl;

        }
 }
