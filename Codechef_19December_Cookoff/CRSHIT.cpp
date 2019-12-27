//This is my solution for 'Crash It' from the December Cookoff
//Question Link: https://www.codechef.com/COOK113B/problems/CRSHIT

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,k;
    cin>>n;
    cin>>q;
    cin>>k;
    int dir[n];
    int D[n];
    int pos[n];
    int X[n];
    fflush(stdin);
    fflush(stdout);
    for(int i=0;i<n;i++)
    {
        cin>>dir[i];
        cin>>pos[i];
        D[i] = dir[i];
        X[i] = pos[i];
    }
    //cout<<"these are the inputs\n";
    /*for(int i=0;i<n;i++)
    {
        cout<<dir[i]<<"\t"<<pos[i]<<endl;
    }
    */
    while(q--)
    {
        int crashes=0;
        for(int i=0;i<n;i++)
        {
            dir[i] = D[i];
            pos[i] = X[i];
        }
        int t;
        cin>>t;
        for(int i=0;i<k;i++)
        {
            //cout<<"\ntime : \n"<<i<<endl;
            for(int j=0;j<n;j++)
            {
                //cout<<"position : "<<pos[j]<<endl;
                if(dir[j] == 1)
                    pos[j]++;
                else if(dir[j]==2)
                    pos[j]--;
                if(pos[j]==k)
                    pos[j]=0;
                if(pos[j]==-1)
                    pos[j] = k-1;
            }
            //cout<<"crashes: "<<crashes<<endl;
            for(int j=0;j<n;j++)
            {
                for(int j2 = 0;j2<n;j2++)
                {
                    if(j2==j)
                        continue;
                    if(pos[j2]==pos[j])
                    {
                        crashes++;
                        //cout<<"class a crash between "<<j2<<" & "<<j<<endl;
                    }

                    if(dir[j]==1 && dir[j2]==2)
                    {
                        if(pos[j]==0 && pos[j2]==k-1)
                        {
                            crashes++;
                            //cout<<"class b crash between "<<j2<<" & "<<j<<endl;
                        }
                        else if((pos[j] - 1) == pos[j2])
                        {
                            crashes++;
                            //cout<<"class c crash between "<<j2<<" & "<<j<<endl;
                        }
                    }
                    else if(dir[j]==2 && dir[j2]==1)
                    {
                        if(pos[j]==k-1 && pos[j2]==0)
                        {
                            crashes++;
                            //cout<<"class d crash between "<<j2<<" & "<<j<<endl;
                        }
                        else if((pos[j2]-1)==pos[j])
                        {
                            crashes++;
                            //cout<<"class e crash between "<<j2<<" & "<<j<<endl;
                        }
                    }

                }

            }

        }
        int crashesfork = crashes;
        int finalcrashes = (t/k)*crashesfork;
        crashes=0;
        t = t%k;
        for(int i=0;i<t;i++)
        {
            //cout<<"\ntime : \n"<<i<<endl;
            for(int j=0;j<n;j++)
            {
                //cout<<"position : "<<pos[j]<<endl;
                if(dir[j] == 1)
                    pos[j]++;
                else if(dir[j]==2)
                    pos[j]--;
                if(pos[j]==k)
                    pos[j]=0;
                if(pos[j]==-1)
                    pos[j] = k-1;
            }
            //cout<<"crashes: "<<crashes<<endl;
            for(int j=0;j<n;j++)
            {
                for(int j2 = 0;j2<n;j2++)
                {
                    if(j2==j)
                        continue;
                    if(pos[j2]==pos[j])
                    {
                        crashes++;
                        //cout<<"class a crash between "<<j2<<" & "<<j<<endl;
                    }

                    if(dir[j]==1 && dir[j2]==2)
                    {
                        if(pos[j]==0 && pos[j2]==k-1)
                        {
                            crashes++;
                            //cout<<"class b crash between "<<j2<<" & "<<j<<endl;
                        }
                        else if((pos[j] - 1) == pos[j2])
                        {
                            crashes++;
                            //cout<<"class c crash between "<<j2<<" & "<<j<<endl;
                        }
                    }
                    else if(dir[j]==2 && dir[j2]==1)
                    {
                        if(pos[j]==k-1 && pos[j2]==0)
                        {
                            crashes++;
                            //cout<<"class d crash between "<<j2<<" & "<<j<<endl;
                        }
                        else if((pos[j2]-1)==pos[j])
                        {
                            crashes++;
                            //cout<<"class e crash between "<<j2<<" & "<<j<<endl;
                        }
                    }

                }

            }

        }
        finalcrashes+=crashes;
        cout<<finalcrashes-4<<endl;
        //I am not sure why crashes-4 works, I did not have enough time to figure out why this is so. Do let me know if you figure this out
    }

}
