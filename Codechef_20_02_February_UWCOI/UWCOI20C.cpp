//This is my solution for 'Mercury Poisoning' from the February UWCOI contest
//Question Link: https://www.codechef.com/UWCOI20/problems/UWCOI20C

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
        int h,w,q;
        int x=0;
        cin>>h>>w>>q;
        for(int i=0;i<h;i++)
        {
            for(int j =0;j<w;j++)
                {
                    cin>>x;
                }
        }
        int a,b,p;
        for(int i=0;i<q;i++)
        {
            cin>>a>>b>>p;
            if(p>x)
            {
                cout<<(h*w)<<endl;
            }
            else
                cout<<0<<endl;
        }
    }
}


