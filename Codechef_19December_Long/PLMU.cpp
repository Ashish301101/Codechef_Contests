//This is my solution for 'Plus Multiply' from the december Long challenge
//Question Link: https://www.codechef.com/DEC19B/problems/PLMU/

#include <bits/stdc++.h>

using namespace std;

unsigned long long ncr(long n, long r)
{
    unsigned long long ans = 1;
    if (n == r)
        return 1;
    for (unsigned long long i = n; i > n - r; i--)
    {
        ans *= i;
        //cout<<ans<<endl;
    }
    //cout<<"aslkf"<<ans<<endl;
    for (unsigned long long i = r; i > 1; i--)
    {
        ans /= r;
        //cout<<ans<<endl;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        long a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long z = 0;
        long tw = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                z++;
            }
            else if (a[i] == 2)
            {
                tw++;
            }
        }
        //cout<<z<<","<<tw<<endl;
        unsigned long long ans = 0;
        if (z > 1)
            ans += ncr(z, 2);
        if (tw > 1)
            ans += ncr(tw, 2);
        cout << ans << endl;
    }
}
