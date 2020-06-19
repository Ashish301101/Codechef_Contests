//This is my solution for 'Chef and Icecream' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/CHFICRM

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
        int ar[n];
        int fives = 0, tens = 0, fifteens = 0, temp = 0;
        int fl = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        for (int i = 0; i < n; i++)
        {
            temp = ar[i];

            if (temp == 5)
            {
                fives++;
            }
            else if (temp == 10)
            {
                tens++;
                if (fives > 0)
                {
                    fives--;
                }
                else
                {
                    cout << "NO" << endl;
                    fl = 0;
                    break;
                }
            }
            else if (temp == 15)
            {
                fifteens++;
                if (tens > 0)
                {
                    tens--;
                }
                else if (fives > 1)
                {
                    fives -= 2;
                }
                else
                {
                    cout << "NO" << endl;
                    fl = 0;
                    break;
                }
            }
        }
        if (fl)
            cout << "YES" << endl;
    }
}