//This is my solution for 'Base Plans' from the February UWCOI contest
//Question Link: https://www.codechef.com/UWCOI20/problems/UWCOI20D

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
        string str[n];
        int cunt = 0;

        int ntemp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
            if (str[i][i] == '1' && i != n - 1)
            {
                ntemp++;
            }
            else
            {
                if (i == n - 1)
                {
                    ntemp++;
                }
                cunt += ntemp * (ntemp + 1) / 2;
                ntemp = 0;
            }
            //cout<<cunt<<endl;
        }
        cout << cunt << endl;
    }
}