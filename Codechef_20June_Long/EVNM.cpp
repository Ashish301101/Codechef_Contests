//This is my solution for 'Even Matrix' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/EVENM

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
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        int odd = n % 2;

        if (odd)
        {
            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {
                    cout << i * n + (j + 1) << " ";
                }
                cout << endl;
            }
        }
        else
        {
            int x = 0;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << i * n + (j + 1) << " ";
                    }
                    cout << endl;
                }
                else
                {
                    for (int j = n; j > 0; j--)
                    {
                        cout << i * n + j << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}