//This is my solution for 'The Tom and Jerry Game!' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/EOEO

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
        long long n;
        cin >> n;

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        if (n % 2 == 1)
        {
            cout << n / 2 << endl;
            continue;
        }
        else
        {
            unsigned long long twos = (n & ~(n - 1)) << 1;
            cout << n / twos << endl;
            continue;
        }
    }
}