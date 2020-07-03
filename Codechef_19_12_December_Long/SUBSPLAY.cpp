//This is my solution for 'Easy Subsequence Selection' from the december Long challenge
//Question Link: https://www.codechef.com/DEC19B/problems/SUBSPLAY/

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
        char s[n];
        int minlen = n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            if (i > 0 && s[i] == s[i - 1])
                minlen = 1;
            else if (i > 1 && s[i] == s[i - 2])
                minlen = 2;
        }
        int q;
        for (int i = 0; i < n - 1; i++)
        {
            q = n;
            for (int j = i + 1; j < q; j++)
            {
                if (s[i] == s[j])
                {
                    q = j;
                    if (j - i < minlen)
                        minlen = j - i;
                }
            }
        }
        cout << (n - minlen) << endl;
    }
}
