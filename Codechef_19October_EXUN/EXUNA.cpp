//this is for the question https://www.codechef.com/EXPP2019/problems/EXUNA

#include <iostream>
#include <algorithm>

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
        int ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }

        sort(ar,ar+n);
        int mod = ar[0];
        for(int i=0;i<n-1;i++)
        {
            mod = mod%ar[i+1];
            //cout<<mod<<",";
        }
        cout<<mod<<endl;

    }
}
