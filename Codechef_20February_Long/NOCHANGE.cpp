//This is my solution for 'No Change' from the February Long Challenge
//Question Link: https://www.codechef.com/FEB20B/problems/NOCHANGE

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
        int p;
        cin>>p;
        vector < int > ar;
        int temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            ar.push_back(temp);
        }

        bool flag=0;
        int flag_ind;

        for(int i=0;i<n;i++)
        {
            if(p%ar[i]!=0)
            {
                flag = 1;
                flag_ind = i;
                break;
            }
        }


        if(!flag)
        {
            bool cond1 = 0,condp = 0;
            int ind1=-1,indp=-1;
            for(int i=0;i<n;i++)
            {
                if(ar[i]==1)
                {
                    cond1 = 1;
                    ind1=i;
                }
                if(ar[i] == p)
                {
                    condp = 1;
                    indp=i;
                }
            }
            if(n==1)
            {
                cout<<"NO"<<endl;
            }
            else if(n==2)
            {
                if(cond1 || condp)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    if(ar[0]%ar[1]==0 || ar[1]%ar[0]==0)
                    {
                        cout<<"NO"<<endl;
                    }
                    else
                    {
                        int l_ind = ar[0]<ar[1]?0:1;
                        int r_ind = ar[0]>ar[1]?0:1;
                        cout<<"YES ";
                        for(int i=0;i<n;i++)
                        {
                            if(i==l_ind)
                            {
                                cout<<((p-ar[r_ind])/ar[l_ind]+1)<<" ";
                            }

                            if(i==r_ind)
                            {
                                cout<<1<<" ";
                            }
                        }
                        cout<<endl;
                    }
                }
            }
            else if(n == 3)
            {
                if(cond1 && condp)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    int t1,t2=-1;
                    for(int i=0;i<n;i++)
                    {
                        if(i!=ind1 && i!=indp)
                        {
                            t1 =  i;
                            break;
                        }
                    }

                    int a[n];
                    for(int i=0;i<n;i++)
                    {
                        a[i] = ar[i];
                    }

                    sort(a,a+n);
                    for(int i=0;i<n-1;i++)
                    {
                        bool tflag = 0;
                        if(i!=ind1 && i!=indp)
                        {
                            t1 = i;
                            for(int j=i+1;j<n;j++)
                            {
                                if(a[j]%a[t1]!=0)
                                {
                                    t2 = j;
                                    tflag=1;
                                    break;
                                }
                            }
                        }

                        if(tflag)
                        {
                            break;
                        }
                    }
                    if(t2==-1)
                    {
                        cout<<"NO"<<endl;
                    }
                    else
                    {
                        int l_ind,r_ind;
                        cout<<"YES ";

                        for(int i=0;i<n;i++)
                        {
                            if(ar[i]==a[t1])
                            {
                                l_ind = i;
                            }
                            if(ar[i]==a[t2])
                            {
                                r_ind = i;
                            }
                        }

                        for(int i=0;i<n;i++)
                        {
                            if(i==l_ind)
                            {
                                cout<<((p-ar[r_ind])/ar[l_ind]+1)<<" ";
                            }

                            else if(i==r_ind)
                            {
                                cout<<1<<" ";
                            }

                            else
                            {
                                cout<<0<<" ";
                            }
                        }
                        cout<<endl;
                    }

                }
            }
            else
            {

                    int t1,t2=-1;
                    for(int i=0;i<n;i++)
                    {
                        if(i!=ind1 && i!=indp)
                        {
                            t1 =  i;
                            break;
                        }
                    }

                    int a[n];
                    for(int i=0;i<n;i++)
                    {
                        a[i] = ar[i];
                    }

                    sort(a,a+n);
                    for(int i=0;i<n-1;i++)
                    {
                        bool tflag = 0;
                        if(i!=ind1 && i!=indp)
                        {
                            t1 = i;
                            for(int j=i+1;j<n;j++)
                            {
                                if(a[j]%a[t1]!=0)
                                {
                                    t2 = j;
                                    tflag=1;
                                    break;
                                }
                            }
                        }

                        if(tflag)
                        {
                            break;
                        }
                    }
                    if(t2==-1)
                    {
                        cout<<"NO"<<endl;
                    }
                    else
                    {
                        int l_ind,r_ind;
                        cout<<"YES ";

                        for(int i=0;i<n;i++)
                        {
                            if(ar[i]==a[t1])
                            {
                                l_ind = i;
                            }
                            if(ar[i]==a[t2])
                            {
                                r_ind = i;
                            }
                        }

                        for(int i=0;i<n;i++)
                        {
                            if(i==l_ind)
                            {
                                cout<<((p-ar[r_ind])/ar[l_ind]+1)<<" ";
                            }

                            else if(i==r_ind)
                            {
                                cout<<1<<" ";
                            }

                            else
                            {
                                cout<<0<<" ";
                            }
                        }
                        cout<<endl;
                    }



            }


        }
        else
        {
            cout<<"YES ";
            for(int i=0;i<n;i++)
            {
                if(i==flag_ind)
                {
                    cout<<(p/ar[i])+1<<" ";
                }
                else
                    cout<<0<<" ";
            }
            cout<<endl;
        }


    }

}