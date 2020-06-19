//This is my solution for 'Chef and String' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/XYSTR

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
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }
}