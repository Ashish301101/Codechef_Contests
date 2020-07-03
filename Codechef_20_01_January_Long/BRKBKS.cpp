//This is my solution for 'Breaking Bricks' from the January Long Challenge
//Question Link: https://www.codechef.com/JAN20B/problems/BRKBKST


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
        int s,w1,w2,w3;
        cin>>s>>w1>>w2>>w3;
        if(s>=(w1+w2+w3))
        {
            cout<<1<<endl;
        }
        else if(s>=(w1+w2) || s>=(w2+w3))
        {
            cout<<2<<endl;
        }
        else
        {
            cout<<3<<endl;
        }
    }

}

