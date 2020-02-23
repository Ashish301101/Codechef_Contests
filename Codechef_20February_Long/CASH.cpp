//This is my solution for 'Hard Cash' from the February Long Challenge
//Question Link: https://www.codechef.com/FEB20B/problems/CASH

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
        int n,k;
        cin>>n>>k;

        long sum=0;

        int temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            sum+=temp;
        }

        cout<<(sum%k)<<endl;

    }

}

