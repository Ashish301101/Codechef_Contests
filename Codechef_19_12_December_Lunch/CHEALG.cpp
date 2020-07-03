//This is my solution for 'Check Algoritm' from the december Lunchtime
//Question Link: https://www.codechef.com/LTIME79B/problems/CHEALG

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
        string s;
        cin >> s;
        int n = s.length();
        int distinctelem = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                distinctelem++;
            }
        }
        int ar[distinctelem];
        int start = -1;
        int cur = 0;
        int idx = 0;
        s += '^';
        int finlen = 0;
        for (int i = 0; i < n; i++)
        {
            cur = i;
            if (s[i] != s[i + 1])
            {
                ar[idx] = cur - start;
                start = cur;
                //cout<<"\tfinlen: "<<finlen<<endl;
                //cout<<s[i]<<ar[idx];
                if (ar[idx] < 10)
                {
                    finlen += 2;
                }
                else if (ar[idx] < 100 && ar[idx] >= 10)
                {
                    finlen += 3;
                }
                else
                    finlen += 4;
                idx++;
            }
        }
        //cout<<endl;
        if (finlen < n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
