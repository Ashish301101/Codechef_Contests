//This is my solution for 'Lasers Everywhere' from the March Long Challenge
//Question Link: https://www.codechef.com/MARCH20B/problems/LAZER

#include <bits/stdc++.h>

using namespace std;

long fun(long l, long r, long y, const vector<long> &ar)
{
    //cout<<*max_element(ar.begin(),ar.begin()+2)<<endl;
    long ma = *(max_element(ar.begin() + (l - 1), ar.begin() + r));
    long mi = *(min_element(ar.begin() + (l - 1), ar.begin() + r));
    if (y > ma || y < mi)
    {
        return 0;
    }
    long m = l + (r - l) / 2;
    long quanta = 15000;
    if (r - l <= quanta)
    {
        long tans = 0;
        for (int i = l; i < r; i++)
        {
            if ((y - ar[i - 1]) * (y - ar[i]) <= 0)
            {
                tans++;
            }
        }
        return tans;
    }
    return fun(l, m, y, ar) + fun(m, r, y, ar);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<long> ar;
        long temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            ar.push_back(temp);
        }
        while (q--)
        {
            long long x1, x2, y;
            cin >> x1 >> x2 >> y;
            long ans = 0;
            ans = fun(x1, x2, y, ar);
            cout << ans << endl;
        }
    }
}
