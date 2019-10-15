//this is for https://www.codechef.com/OCT19B/problems/SAKTAN
#include <iostream>
#include <algorithm>


using namespace std;

void do_stuff()
{
    int n,m,q;
    cin>>n>>m>>q;
    int rows[q];
    int cols[q];
    long odd = 0;
    for(int i=0;i<q;i++)
    {
        cin>>rows[i]>>cols[i];
        rows[i]--;
        cols[i]--;
    }
    sort(rows, rows+q);
    sort(cols, cols+q);

    int distinctr = 1;
    int distinctc = 1;

    //2,2,2,4,4,5,6,12,13
    //1,1,2,3,4,5,6
    for(int i=0;i<q-1;i++)
    {
        if(rows[i]!=rows[i+1])
            distinctr++;
        if(cols[i]!=cols[i+1])
            distinctc++;
    }
    //cout<<distinctc<<","<<distinctr<<endl;

    int rfreq[distinctr];
    int cfreq[distinctc];

    for(int i=0;i<distinctc;i++)
    {
        cfreq[i]=1;
    }
    for(int i=0;i<distinctr;i++)
    {
        rfreq[i]=1;
    }

    int i=distinctc-1;
    for(int j=q-1;j>0;j--)
    {
        if(cols[j]==cols[j-1])
        {
            cfreq[i]++;
            //cout<<cols[j]<<"is equal to "<<cols[j-1]<<" and rfreq at "<<i<<" is "<<rfreq[i];
            //cout<<" j = "<<j<<endl;
        }
        else{
            //cout<<cols[j]<<"is not equal to "<<cols[j-1]<<" and rfreq at "<<i<<" is "<<rfreq[i];
            //cout<<" j = "<<j<<endl;
            i--;
        }
    }

    i=distinctr-1;
    for(int j=q-1;j>0;j--)
    {
        if(rows[j]==rows[j-1])
        {
            rfreq[i]++;
            //cout<<cols[j]<<"is equal to "<<cols[j-1]<<" and cfreq at "<<i<<" is "<<cfreq[i];
            //cout<<" j = "<<j<<endl;
        }
        else{
            //cout<<cols[j]<<"is not equal to "<<cols[j-1]<<" and cfreq at "<<i<<" is "<<cfreq[i];
            //cout<<" j = "<<j<<endl;
            i--;
        }
    }
    int k;
    for(int j=0,k=0;j<q;)
    {

        if(rfreq[k]%2==1)
        {
            odd+=m-distinctc;
            //cout<<"odd = "<<odd<<" y is "<<cols[j]<<" freq is "<<rfreq[k]<<endl;
            j+=rfreq[k];
            k++;
        }
        else
        {
            j+=rfreq[k];
            k++;
        }
        //cout<<"j = "<<j<<" k = "<<k<<" odd = "<<odd<<" y is "<<cols[j]<<" freq is "<<rfreq[k]<<endl;

    }

    for(int j=0,k=0;j<q;)
    {

        if(cfreq[k]%2==1)
        {
            odd+=n-distinctr;
            j+=cfreq[k];
            k++;
        }
        else
        {
            j+=cfreq[k];
            k++;
        }
        //cout<<"j = "<<j<<" k = "<<k<<" odd = "<<odd<<" x is "<<rows[j]<<" freq is "<<cfreq[k]<<endl;
    }

    for(int j=0;j<distinctr;j++)
    {
        for(int k=0;k<distinctc;k++)
        {
            if((rfreq[j]+cfreq[k])%2==1)
                {
                    odd++;

                }
            //cout<<"odd = "<<odd<<" row,column number "<<cols[rfreq[j]]<<","<<rows[cfreq[k]]<<endl;
        }
    }
    cout<<odd<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short t;
    cin>>t;
    while(t--)
    {
        do_stuff();
    }
}
