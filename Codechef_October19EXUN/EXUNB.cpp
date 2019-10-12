//this is for the question https://www.codechef.com/EXPP2019/problems/EXUNB

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
        if(n%2==1)
        {
            cout<<"YES"<<endl;
            bool ar[n][n];
            for(int i = 0;i<n;i++)
            {
                for(int j = i+1;j<n;j++)
                {
                    if((i+j)%2==1)
                    {
                        ar[i][j] = 1;
                        ar[j][i] = 0;
                    }
                    else
                    {
                        ar[i][j] = 0;
                        ar[j][i] = 1;
                    }
                }
                ar[i][i] = 0;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<ar[i][j];
                }
                cout<<endl;
            }

        }

        else
        {
            cout<<"NO"<<endl;
        }

    }

}
