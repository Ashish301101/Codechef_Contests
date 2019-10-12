#include <iostream>
//#include<algorithm>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t;
    //cin>>t;
    t = 5;
    while(t--   )
    {

        int n;
        int Q;
        int p;
        int q;
        cin>>n>>Q;
        int b[n-1];
        for(int i = 0;i<n-1;i++)
        {
         cin>>b[i];
        }
        while(Q--)
        {
            long sum = 0;
            cin>>p>>q;
            int temp;
            if(p>q)
            {
                temp = p;
                p = q;
                q = temp;
            }
            cout<<(q-p)<<"is diff"<<endl;
            cout<<((q-p)%2)<<endl;
            if((q-p)%2==1)
            {
                int x = 0;
                for(int i = p-1;i<q-1;i++,x++)
                {
                    if(x%2==0)
                    {
                      sum+=b[i];
                    }
                    else
                    {
                        sum-=b[i];
                    }
                    //cout<<sum<<","<<x<<";";
                }
                cout<<sum<<endl;
            }
            else
            {
                cout<<"UNKNOWN"<<endl;
            }
        }



    }

}
