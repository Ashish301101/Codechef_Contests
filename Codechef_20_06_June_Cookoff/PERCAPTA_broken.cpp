//This is my solution for 'Per Capita Income' from the June Cookoff
//Question Link: https://www.codechef.com/COOK119B/problems/PERCAPTA

#include <bits/stdc++.h>

using namespace std;
vector <int> tempans;
int n,siz=0;

void dfs(vector <vector <int>> ar, int vis[], int node)
{
    //printf("%d ", node + 1);
    tempans.push_back(node+1);
    siz++;
    vis[node] = 1;
    int tovis[n];
    for (int i = 0; i < n; i++)
    {
        tovis[i] = 0;
        if (ar[node][i] == 1)
        {
            tovis[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (tovis[i] == 1 && vis[i] == 0)
        {
            dfs(ar, vis, i);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int m;
        cin>>n>>m;
        //N=n;
        int maxsiz = 0;
        vector <vector <int> > road;

        for(int i=0;i<n;i++)
        {
            vector <int> useless;
            for(int j=0;j<n;j++)
            {
                useless.push_back(0);
            }
            road.push_back(useless);
        }

        float ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        int temp;
        float maxgdp = 0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            ar[i]/=temp;
            if(ar[i]>maxgdp)
            {
                maxgdp = ar[i];
            }
        }
        int temp2;
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            cin>>temp2;
            road[temp-1][temp2-1] =1;
            road[temp2-1][temp-1] = 1;
        }

        for(int i=0;i<n;i++)
        {
            if(ar[i]<maxgdp)
            {
                ar[i]=0;
                for(int j=0;j<n;j++)
                {
                    road[i][j] = 0;
                    road[j][i] = 0;
                }
            }
        }

        //bfs on each node
        vector <int> finans;
        int vis[n];
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
        }
        for(int i=0;i<n;i++)
        {
            if(ar[i]==0)
            {
                continue;
            }
            if(vis[i] == 0)
            {
                tempans.clear();
                siz=0;

                dfs(road,vis,i);
                if(maxsiz<siz)
                {
                    maxsiz = siz;
                    finans.clear();
                    finans = tempans;
                }
            }


        }

        cout<<maxsiz<<endl;
        for(int i=0;i<finans.size();i++)
        {
            cout<<finans[i]<<" ";
        }
        cout<<endl;

    }
}