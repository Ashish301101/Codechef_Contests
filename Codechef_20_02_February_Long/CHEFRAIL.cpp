//This is my solution for 'Chef and Railway Stations' from the February Long Challenge
//Question Link: https://www.codechef.com/FEB20B/problems/CHEFRAIL

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
        int m,n;
        cin>>m>>n;
        vector < int > x;
        vector <int > y;
        int temp;
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            x.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            y.push_back(temp);
        }

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        int counter=0;

        int xzeros=0;
        int yzero=0;
        
        for(int i=0;i<m;i++)
        {
            //chooose x

            for(int j=0;j<n-1;j++)
            {
                //choose y1

                for(int k=j+1;k<n;k++)
                {
                    //choose y2

                    if(y[j]*y[k]== -1*x[i]*x[i])
                    {
                        counter++;
                    }

                }

            }
            
            if(x[i]==0)
            {
                xzeros = 1;
            }
        }

        
        
        for(int i=0;i<n;i++)
        {
            //chooose x

            for(int j=0;j<m-1;j++)
            {
                //choose y1

                for(int k=j+1;k<m;k++)
                {
                    //choose y2

                    if(x[j]*x[k]== -1*y[i]*y[i])
                    {
                        counter++;
                    }

                }

            }
            
            if(y[i]==0)
            {
                yzero=1;
            }
        }
        
        if(xzeros==1 && yzero==0)
           {
               counter+= (m-1)*n;
           }
        else if(yzero==1 && xzeros==0)
        {
            counter += (n-1)*m;
        }
        else if(xzeros==1 && yzero == 1)
        {
            counter +=(m-1)*(n-1);
        }
        
        cout<<counter<<endl;

    }

}

