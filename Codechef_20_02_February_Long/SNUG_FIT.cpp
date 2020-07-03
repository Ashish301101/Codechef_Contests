
//This is my solution for 'Snug fit' from the February Long challenge
//Question Link: hhttps://www.codechef.com/FEB20B/problems/SNUG_FIT

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
        vector <int> a;
        vector <int> b;
        int n;
        cin>>n;

        int temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            a.push_back(temp);
        }

        for(int i=0;i<n;i++)
        {
            cin>>temp;
            b.push_back(temp);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        long sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=a[i]>b[i]?b[i]:a[i];
        }
        cout<<sum<<endl;

    }

}

