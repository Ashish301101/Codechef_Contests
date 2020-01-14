//This is my solution for 'Doofish Matrix' from the January Long Challenge
//Question Link: https://www.codechef.com/JAN20B/problems/DFMTRX

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
        int n;
        cin>>n;

        if(n==1)
        {
            cout<<"Hooray"<<endl;
            cout<<"1"<<endl;
            continue;
        }

        int ar[n][n];
        ar[0][0]=1;
        int horskip = 1;
        int verskip = 1;
        int p=0;
        int ppow=1;
        int boo = 0;
        int ncpy=n;
        for(int i=0;i<10;i++)
        {
            if(ncpy%2==0 && ncpy!=1)
            {
                ncpy/=2;
            }
            else if(ncpy==1)
            {
                break;
            }
            else
            {
                boo=1;
                break;
            }
        }
        if(boo==1)
        {
            if(n%2==1)
            {
                cout<<"Boo"<<endl;
                continue;
            }
            else
            {   cout<<"Hooray"<<endl;
                /*for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        ar[i][j]=0;
                    }
                }*/

                for(int i=0;i<n;i++)
                {
                    for(int j=i;j<n;j++)
                    {
                        if(i==j)
                        {
                            ar[i][j] = (2*n)-1;
                        }
                        else if(i==0)
                        {
                            ar[i][j] = j;
                        }

                        else if(j==n-1)
                        {
                            ar[i][j] = ar[i-1][i]+1;
                            if(ar[i][j]==0)
                            {
                                ar[i][j]=n-1;

                            }
                        }

                        else
                        {
                            ar[i][j] = ar[i-1][j]+1;
                            if(ar[i][j]==0)
                            {
                                ar[i][j] = n-1;
                            }

                        }
                        if(ar[i][j]==n)
                        {
                            ar[i][j] = 1;
                        }
                        if(i!=j)
                        ar[j][i] = ar[i][j]+n-1;
                    }
                }

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        cout<<ar[i][j]<<" ";
                    }
                    cout<<endl;
                }

            }
        }
        else
        {
            cout<<"Hooray"<<endl;
            for(int i=0;i<n;i++)
            {
                if((i)==2*ppow && i!=0)
                {
                    p++;
                    ppow = pow(2,p);
                }
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                    {
                        ar[i][j]=1;
                    }
                    else if(i==0)
                    {
                        ar[i][j]=ar[i][j-1]+2;
                    }

                    else if(j<ppow)
                    {
                        ar[i][j]=ar[i-ppow][j+ppow]-1;
                    }
                    else if(j>=ppow)
                    {
                        if(j%(2*ppow)>=ppow)
                        {
                            ar[i][j]=ar[i-ppow][j-ppow];
                        }
                        else
                        {
                            ar[i][j]=ar[i-ppow][j+ppow];
                        }
                    }
                    cout<<ar[i][j]<<" ";
                }
                cout<<endl;

            }
        }
    }
}

