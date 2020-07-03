//This is my solution for 'Not All Flavours' from the February Lunchtime Challenge
//Question Link: https://www.codechef.com/LTIME81B/problems/NOTALLFL

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ar[n];
        //vector <int> dist[k];
        ar[0] = k + 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> ar[i];
        }
        ar[n + 1] = k + 1;
        int occur_first[k + 1] = {0};
        int occur_last[k + 1];
        for (int i = 0; i < k + 1; i++)
        {
            occur_last[i] = n + 1;
        }
        int occur[k + 1] = {0};
        int dist[k + 1] = {0};
        int real_first[k + 1] = {0};
        //cout<<occur_last[3]<<endl;
        for (int i = 1; i < n + 1; i++)
        {
            if (occur[ar[i]] == 0)
            {
                occur_first[ar[i]] = i;
                occur[ar[i]]++;
                dist[ar[i]] = occur_last[ar[i]] - occur_first[ar[i]] - 1;
                real_first[ar[i]] = i;
            }
            else if (occur[ar[i]] == 1)
            {
                occur_last[ar[i]] = i;
                occur[ar[i]]++;
                dist[ar[i]] = occur_last[ar[i]] - occur_first[ar[i]] - 1;
            }
            else
            {
                occur_first[ar[i]] = occur_last[ar[i]];
                occur_last[ar[i]] = i;
                if ((occur_last[ar[i]] - occur_first[ar[i]] - 1) > dist[ar[i]])
                {
                    dist[ar[i]] = occur_last[ar[i]] - occur_first[ar[i]] - 1;
                }
            }
            //cout<<"elem: "<<ar[i]<<"occur: "<<occur[ar[i]]<<"first: "<<occur_first[ar[i]]<<"last: "<<occur_last[ar[i]]<<"dist: "<<dist[ar[i]]<<endl;
        }
        //cout<<endl;
        for (int i = 1; i <= k; i++)
        {
            //cout<<"elem: "<<i<<"|occur: "<<occur[i];
            if (occur[i] == 0)
            {
                //cout<<"|dist: "<<dist[i]<<endl;
                dist[i] = n;
                break;
            }
            else if (occur[i] == 1)
            {
                //cout<<"|first: "<<real_first[i]<<"|dist_ini: "<<dist[i];
                int d1 = occur_first[i] - 1;
                int temp = dist[i];
                dist[i] = temp > d1 ? temp : d1;
                //cout<<"|final dist: "<<dist[i]<<endl;
            }
            else
            {
                //cout<<"|first: "<<real_first[i]<<"|last: "<<occur_last[i]<<"|dist_ini: "<<dist[i];
                int d1 = real_first[i] - 1;
                int d2 = n + 1 - occur_last[i] - 1;
                int d3 = d2 > d1 ? d2 : d1;
                //cout<<"|d1: "<<d1<<"|d2: "<<d2;
                //cout<<"|d3: "<<d3;
                int temp = dist[i];
                dist[i] = temp > d3 ? temp : d3;
                //cout<<"|final dist: "<<dist[i]<<endl;
            }
        }
        int distmax = 0;
        for (int i = 1; i <= k; i++)
        {
            if (dist[i] > distmax)
            {
                distmax = dist[i];
            }
        }
        cout << distmax << endl;
    }
}
