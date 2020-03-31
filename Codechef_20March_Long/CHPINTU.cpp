//This is my solution for 'Pintu and Fruits' from the March Long Challenge
//Question Link: https://www.codechef.com/MARCH20B/problems/CHPINTU

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
        int n, m;
        cin >> n >> m; //n is number of baskets, m is number of fruits types
        vector<int> fincost(m, 0);
        vector<int> basket;
        vector<int> bascost;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            basket.push_back(x);
        }
        set<int> unused;
        for (int i = 0; i < m; i++)
        {
            unused.insert(i);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            bascost.push_back(x);
            unused.erase(basket[i] - 1);
            //            cout<<basket[i]<<"\t";
            //            cout<<bascost[i]<<endl;
            //            cout<<fincost[basket[i]-1]<<endl;
            fincost[basket[i] - 1] += bascost[i];
            //cout<<fincost[basket[i]-1]<<" @ "<<basket[i]-1<<endl;
        }
        int mincost = 999999;
        for (int i = 0; i < m; i++)
        {
            if (mincost > fincost[i] && unused.find(i) == unused.end())
            {
                mincost = fincost[i];
            }
        }
        cout << mincost << endl;
    }
}
