//This is my solution for 'Peak Finding' from the February UWCOI contest
//Question Link: https://www.codechef.com/UWCOI20/problems/UWCOI20A

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
        vector<int> ar;

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > maxi)
            {
                maxi = x;
            }
        }
        cout << maxi << endl;
    }
}
