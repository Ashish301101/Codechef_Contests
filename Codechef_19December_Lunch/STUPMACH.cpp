//This is my solution for 'Stupid Machine' from the december Lunchtime
//Question Link: https://www.codechef.com/LTIME79B/problems/STUPMACH

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
        long n;
        cin >> n;
        long s[n];
        for (long i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        long ans = 0;

        long minreq = 0;
        while (s[0] > minreq)
        {
            long minelem = s[0];
            long minidx = 0;
            for (long i = 0; i < n; i++)
            {
                if (s[i] < minelem)
                {
                    minelem = s[i];
                    minidx = i;
                }
            }
            //cout<<"minelem: "<<minelem<<" idx: "<<minidx<<" ans: "<<ans<<endl;
            if (minelem == minreq)
            {
                n = minidx;
                ans += n;
            }
            else if (minelem > minreq)
            {
                ans += n;
            }
            minreq++;
        }
        cout << ans << endl;
    }
}
