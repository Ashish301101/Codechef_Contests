//This is my solution for 'Evil Professor' from the december Lunchtime
//Question Link: https://www.codechef.com/LTIME79B/problems/EVIPRO

#include <bits/stdc++.h>

using namespace std;

int func(string s, int l, int r, int n)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            ans++;
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
        string s;
        cin >> s;
        int finans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                finans += func(s, i, j, n);
            }
        }
        cout << finans << endl;
    }
}
