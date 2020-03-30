//This is my solution for 'All the Gates' from the February Lunchtime Challenge
//Question Link: https://www.codechef.com/LTIME81B/problems/POPGATES

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
        char str[n];
        int headcount = 0;
        int tailcount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
            if (str[i] == 'H')
            {
                headcount++;
            }
            else
            {
                tailcount++;
            }
        }
        int counting = 1;
        for (int i = n - 1; i > n - 1 - k; i--)
        {
            if (counting == 1)
            {
                if (str[i] == 'H')
                {
                    headcount--;
                    swap(tailcount, headcount);
                    counting = -1;
                }
                else
                {
                    tailcount--;
                }
            }
            else
            {
                if (str[i] == 'T')
                {
                    headcount--;
                    swap(tailcount, headcount);
                    counting = 1;
                }
                else
                {
                    tailcount--;
                }
            }
        }
        cout << headcount << endl;
    }
}
