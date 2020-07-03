//This is my solution for 'Chef and Dynamo' from the January Long Challenge
//Question Link: https://www.codechef.com/JAN20B/problems/DYNAMO 


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
        unsigned long long a,b,c,d,e,s,n,m=1;
        cin>>n;
        cin>>a;
        for(int i=0;i<n;i++)
            m*=10;
        s = a+2*m;
        cout<<s<<endl;
        cin>>b;
        cout<<m-b<<endl;
        cin>>d;
        cout<<m-d<<endl;
        int result;
        cin>>result;
        if(result == -1)
            break;
    }

}
