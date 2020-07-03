//this is for https://www.codechef.com/OCT19B/problems/S10E/

#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short t;
    cin>>t;
    while(t--)
    {
        short n;
        short c = 0;
        cin>>n;
        int p[n+5];
        for(int i = 0;i<5;i++)
        {
            p[i] = 751;
        }
        for(int i = 5;i<n+5;i++)
        {
            cin>>p[i];
            if(p[i]<p[i-1]&&p[i]<p[i-2]&&p[i]<p[i-3]&&p[i]<p[i-4]&&p[i]<p[i-5])
            {
                c++;
            }
        }
        cout<<c<<endl;

    }

}
