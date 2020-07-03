//This is my solution for 'Doraemon' from the January Long Challenge
//Question Link: https://www.codechef.com/JAN20B/problems/CHFDORA

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
        cin>>n>>m;
        int ar[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ar[i][j];
            }
        }
        //cout<<min(m,n)<<endl;
        unsigned long answer = m*n;
        for(int k=3;k<=min(m,n);k+=2)
        {
            for(int i=k/2;i<(n-k/2);i++)
            {
                for(int j = k/2;j<(m-k/2);j++)
                {
                    int flag=0;
                    for(int p=0;p<k/2;p++)
                    {
                        if(ar[i-k/2+p][j]!= ar[i+k/2-p][j] || ar[i][j-k/2+p]!=ar[i][j+k/2-p])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        answer++;
                    }
                }
            }
        }
        cout<<answer<<endl;

    }
}
