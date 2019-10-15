//this is for https://www.codechef.com/OCT19B/problems/MARM

#include <iostream>

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
        long k;
        cin>>n>>k;
        int ar[n];
        for(int i =0;i<n;i++)
        {
            cin>>ar[i];
        }
        if(n%2==1 && k >(n/2))
            ar[(n)/2] = 0;
        k = k%(3*n);

        //cout<<k<<endl;

        int a,b,r;
        for(int i=0;i<k;i++)
        {
            r = i%n;
            a = ar[r];
            b = ar[n-1-r];
            //cout<<"a "<<a<<"b "<<b<<" a^b is "<<(a^b)<<endl;
            ar[r] = a^b;
        }
        for(int i=0;i<n;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }

}
