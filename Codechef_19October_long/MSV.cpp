//this is for https://www.codechef.com/OCT19B/problems/MSV
#include <iostream>
//#include<algorithm>


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
        int starmax = 0;
        int star;
        for(int i=0;i<n;i++)
        {
            star = 0;
            for(int j=0;j<i && i > star;j++)
            {
                if(ar[j]>=ar[i])
                {
                    if(ar[j]%ar[i]==0)
                    {
                        star++;
                    }
                }
            }
            if(star>starmax)
            {
                starmax = star;
            }
        }
        cout<<starmax<<endl;

    }
}
