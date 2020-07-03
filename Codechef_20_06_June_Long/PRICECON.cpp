//This is my solution for 'Chef and Price Control' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/PRICECON

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

        long sum1 = 0;
        long sum2 = 0;

        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            sum1 += temp;
            sum2 += min(temp, k);
        }
        cout << sum1 - sum2 << endl;
    }
}
